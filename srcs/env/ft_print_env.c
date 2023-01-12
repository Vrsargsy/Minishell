/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:10:17 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 05:40:04 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print_env(int fd)
{
	t_env	*node;
	int		i;

	node = g_mini.env;
	while (node)
	{
		i = 0;
		ft_putstr_fd("declare -x ", fd);
		while (node->value[i] && node->value[i] != '=')
			ft_putchar_fd(node->value[i++], fd);
		ft_putstr_fd("=\"", fd);
		i++;
		while (node->value[i])
			ft_putchar_fd(node->value[i++], fd);
		ft_putstr_fd("\"\n", fd);
		node = node->next;
	}
}
