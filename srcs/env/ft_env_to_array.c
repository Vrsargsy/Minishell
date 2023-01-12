/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_to_mx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:01:37 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 05:28:31 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_env_to_mx(t_env *env)
{
	t_env	*node;
	char	**mx;
	int		i;

	node = env;
	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	mx = (char **)malloc(sizeof(char *) * i + 1);
	node = env;
	i = 0;
	while (node)
	{
		mx[i++] = node->value;
		node = node->next;
	}
	mx[i] = NULL;
	return (mx);
}
