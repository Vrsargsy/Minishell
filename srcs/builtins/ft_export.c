/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:00:45 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 07:58:45 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	export_fail(char *var, int *stat)
{
	ft_putstr_fd("minishell: export: `", STDERR);
	ft_putstr_fd(var, STDERR);
	ft_putstr_fd("': not a valid identifier\n", STDERR);
	*stat = 1;
}

static void	ft_export_tok_cmd_variable(t_cmd *cmd, int *stat)
{
	int	i;

	i = 1;
	while (cmd->args[i])
	{
		if (!ft_is_valid_decl(cmd->args[i]))
		{
			export_fail(cmd->args[i++], stat);
			continue ;
		}
		if (ft_in_env(cmd->args[i]))
		{
			if (ft_strchr(cmd->args[i], '='))
				ft_rm_from_env(cmd->args[i]);
			else
			{
				*stat = 0;
				i++;
				continue ;
			}
		}
		ft_add_to_env(ft_strdup(cmd->args[i]));
		*stat = 0;
		i++;
	}
}

int	ft_export_tok_cmd(t_cmd *cmd)
{
	int	stat;

	stat = 0;
	if (ft_matrixlen(cmd->args) == 1)
		ft_print_env(cmd->out);
	else
		ft_export_tok_cmd_variable(cmd, &stat);
	return (stat);
}
