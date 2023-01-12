/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:10:48 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 05:41:22 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	increment_shell_level(t_env *env)
{
	char	*shlvl_value;
	int		shlvl;
	t_env	*node;

	node = env;
	shlvl_value = getenv("SHLVL");
	if (ft_strcmp(shlvl_value, "") == 0)
		return ;
	shlvl = ft_atoi(shlvl_value) + 1;
	while (node && node->next)
	{
		if (ft_strncmp("SHLVL", node->value, 5) == 0)
		{
			node->value = ft_strjoin("SHLVL=", ft_itoa(shlvl));
			return ;
		}
		node = node->next;
	}
}
