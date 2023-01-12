/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:00:13 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 07:56:21 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_withopt(char **args)
{
	int	i;

	i = 1;
	if (ft_strlen(args[1]) < 2 || args[1][0] != '-' || args[1][1] != 'n')
		return (0);
	while (args[1][i])
	{
		if (args[1][i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_echo(t_cmd *cmd)
{
	int	flag;
	int	i;

	flag = is_withopt(cmd->args);
	if (flag)
		i = 2;
	else
		i = 1;
	if (!cmd->args[i])
	{
		if (!flag)
			ft_putstr_fd("\n", cmd->out);
		return (0);
	}
	while (cmd->args[i])
	{
		ft_putstr_fd(cmd->args[i], cmd->out);
		i++;
		if (cmd->args[i])
			ft_putstr_fd(" ", cmd->out);
	}
	if (!flag)
		ft_putstr_fd("\n", cmd->out);
	return (0);
}
