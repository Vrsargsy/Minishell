/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:18:51 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 03:18:52 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_cmd	*ft_find_command(pid_t pid)
{
	int	i;

	i = 0;
	while (i < g_mini.cmd_count)
	{
		if (g_mini.fam[i] == pid)
			return (&g_mini.commands[i]);
		i++;
	}
	return (NULL);
}
