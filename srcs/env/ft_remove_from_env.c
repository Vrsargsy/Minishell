/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_from_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:10:23 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 03:10:24 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_rm_from_env(char *str)
{
	t_env	*node;
	t_env	*prev;

	node = g_mini.env;
	prev = NULL;
	while (node)
	{
		if (!ft_strcmp(ft_sep_identifier(node->value),
				ft_sep_identifier(str)))
		{
			if (prev == NULL)
				g_mini.env = node->next;
			else
				prev->next = node->next;
			node->next = NULL;
			node = NULL;
			break ;
		}
		prev = node;
		node = node->next;
	}
}
