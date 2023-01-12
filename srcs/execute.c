/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:14:32 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 08:16:02 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	close_fds(void)
{
	int	i;

	i = 0;
	while (i < g_mini.cmd_count)
	{
		if (g_mini.commands[i].in != 0)
			close(g_mini.commands[i].in);
		if (g_mini.commands[i].out != 1)
			close(g_mini.commands[i].out);
		i++;
	}
}

static int	ft_exec_builtin(t_cmd *cmd)
{
	int	ret;

	ret = ft_convert_builtin(cmd->args[0]);
	if (ret == _ECHO)
		g_mini.status = ft_echo(cmd);
	else if (ret == _CD)
		g_mini.status = ft_cd(cmd);
	else if (ret == _PWD)
		g_mini.status = ft_pwd(cmd);
	else if (ret == _EXPORT)
		g_mini.status = ft_export_tok_cmd(cmd);
	else if (ret == _UNSET)
		g_mini.status = ft_unset(cmd);
	else if (ret == _ENV)
		g_mini.status = ft_env(cmd);
	else if (ret == _EXIT)
		ft_exit(cmd);
	if (ret)
		return (0);
	return (-1);
}

static void	transfer_binars(t_cmd *cmd)
{
	char	**path;
	char	*tmp;
	int		i;

	if (ft_exec_builtin(cmd) == -1)
	{
		execve(cmd->args[0], cmd->args, ft_env_to_mx(g_mini.env));
		if (ft_getenv("PATH"))
		{
			path = ft_split(ft_getenv("PATH"), ':');
			i = 0;
			while (path[i])
			{
				tmp = ft_strjoin3(path[i], "/", cmd->args[0]);
				execve(tmp, cmd->args, ft_env_to_mx(g_mini.env));
				free(tmp);
				i++;
			}
			ft_free_matrix(path);
			ft_minishell_error(ft_strjoin(cmd->args[0], ": command not found"));
		}
		else
			ft_minishell_error(ft_strjoin(cmd->args[0],
					": No such file or directory"));
	}
}

void	ft_exec(t_cmd *cmd)
{
	if (!ft_convert_builtin(cmd->args[0]) || g_mini.cmd_count != 1)
	{
		if (dup2(cmd->out, STDOUT) == -1 || dup2(cmd->in, STDIN) == -1)
		{
			perror("minishell: failed dup2");
			exit(1);
		}
		close_fds();
		cmd->out = 1;
	}
	if (cmd->args[0][0] == '/')
	{
		execve(cmd->args[0], cmd->args, ft_env_to_mx(g_mini.env));
		ft_minishell_error(ft_strjoin(cmd->args[0],
				": No such file or directory"));
	}
	else
		transfer_binars(cmd);
	if (g_mini.cmd_count != 1 || !ft_convert_builtin(cmd->args[0]))
	{
		if (ft_convert_builtin(cmd->args[0]))
			exit(g_mini.status);
		exit(UNKNOWN_COMMAND);
	}
}
