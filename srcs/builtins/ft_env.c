/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:00:19 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 05:19:22 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_env(t_cmd *cmd)
{
	t_env	*headnode;

	headnode = g_mini.env;
	if (ft_matrixlen(cmd->args) > 1)
	{
		ft_minishell_error("minishell: env: Too many args to env");
		return (1);
	}
	while (headnode)
	{
		ft_putstr_fd(headnode->value, cmd->out);
		ft_putstr_fd("\n", cmd->out);
		headnode = headnode->next;
	}
	return (0);
}
