/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:01:00 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 08:19:20 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	unset_err(char *str)
{
	ft_putstr_fd("minishell: unset: `", STDERR);
	ft_putstr_fd(str, STDERR);
	ft_putstr_fd("': not a valid identifier\n", STDERR);
}

static int	ft_unset_var(t_cmd *cmd)
{
	int	i;
	int	status;

	i = 1;
	while (cmd->args[i])
	{
		if (!ft_is_valid_id(cmd->args[i]))
		{
			unset_err(cmd->args[i++]);
			status = 1;
			continue ;
		}
		if (ft_in_env(cmd->args[i]))
		{
			ft_rm_from_env(cmd->args[i]);
			status = 0;
		}
		i++;
	}
	return (status);
}

int	ft_unset(t_cmd *cmd)
{
	if (ft_matrixlen(cmd->args) == 1)
	{
		ft_minishell_error("minishell: Invalid number of args to unset");
		return (1);
	}
	return (ft_unset_var(cmd));
}
