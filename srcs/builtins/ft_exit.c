/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:00:39 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 07:57:00 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	terminate(int exit_status)
{
	if (g_mini.cmd_count == 1)
	{
		if (!g_mini.status)
			exit(exit_status);
	}
	else
	{
		if (!exit_status)
			exit(g_mini.status);
		exit(exit_status);
	}
}

void	ft_exit(t_cmd *cmd)
{
	int	exit_status;

	g_mini.status = 0;
	exit_status = 0;
	if (g_mini.cmd_count == 1)
		ft_putstr_fd("exit \n", STDERR);
	if (ft_matrixlen(cmd->args) == 1)
		exit(0);
	if (!ft_isnum(cmd->args[1]))
	{
		exit_status = 255;
		ft_minishell_error("minisell: exit: numeric argument required");
	}
	else
	{
		if (ft_matrixlen(cmd->args) == 2)
			exit_status = ft_atoi(cmd->args[1]);
		else
			g_mini.status = ft_minishell_error("minishell: too many args");
	}
	terminate(exit_status);
}
