/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:01:14 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 05:26:47 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	equal_check(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	ft_add_to_env(char *arg)
{
	t_env	*node;

	node = g_mini.env;
	if (!equal_check(arg))
		arg = ft_strjoin(arg, "=");
	while (node)
	{
		if (node->next == NULL)
		{
			node->next = new_node(arg, NULL);
			break ;
		}
		node = node->next;
	}
}
