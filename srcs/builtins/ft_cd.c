/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:00:07 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 08:09:32 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_old_pwd(t_cmd *cmd)
{
	if (cmd->args[1][0] == '/' || !cmd->args[1] || cmd->args[1][0] == '-')
		return (ft_strdup(ft_getenv("PWD")));
	else
		return (getcwd(NULL, 0));
}

static int	ft_change_dir(t_cmd *cmd, int *status, char *oldpwd)
{
	if (cmd->args[1][0] == '-' && cmd->args[1][1] == '\0')
	{
		if (ft_getenv("OLDPWD"))
		{
			*status = ft_abs(chdir(ft_getenv("OLDPWD")));
			if (!*status)
			{
				ft_putstr_fd(ft_getenv("OLDPWD"), cmd->out);
				ft_putstr_fd("\n", cmd->out);
			}
		}
		else
		{
			free(oldpwd);
			return (ft_minishell_error("cd: OLDPWD not set"));
		}
	}
	else
		*status = ft_abs(chdir(cmd->args[1]));
	return (0);
}

static int	update_env_wds(char *oldpwd, int status)
{
	char	*pwd;
	t_cmd	export_t_cmd;

	if (status)
	{
		free(oldpwd);
		return (ft_minishell_error("minishell: cd: No such file or directory"));
	}
	pwd = getcwd(NULL, 0);
	export_t_cmd.args = ft_calloc(3, sizeof(char *));
	export_t_cmd.args[0] = ft_strdup("");
	export_t_cmd.args[1] = ft_strjoin("PWD=", pwd);
	ft_export_tok_cmd(&export_t_cmd);
	ft_free_matrix(export_t_cmd.args);
	free(pwd);
	export_t_cmd.args = ft_calloc(3, sizeof(char *));
	export_t_cmd.args[0] = ft_strdup("");
	export_t_cmd.args[1] = ft_strjoin("OLDPWD=", oldpwd);
	ft_export_tok_cmd(&export_t_cmd);
	ft_free_matrix(export_t_cmd.args);
	free(oldpwd);
	return (status);
}

int	ft_cd(t_cmd *cmd)
{
	int		status;
	char	*old_pwd;

	status = 1;
	old_pwd = get_old_pwd(cmd);
	if (!old_pwd)
	{
		perror("cd: could not retrive current directory");
		return (0);
	}
	if (ft_matrixlen(cmd->args) == 1)
	{
		if (ft_getenv("HOME"))
			status = ft_abs(chdir(ft_getenv("HOME")));
		else
		{
			free(old_pwd);
			return (ft_minishell_error("cd: HOME is not set"));
		}
	}
	else
		if (ft_change_dir(cmd, &status, old_pwd))
			return (1);
	return (update_env_wds(old_pwd, status));
}
