/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:18:32 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 03:18:33 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_args_size(int index)
{
	int		size;

	size = 0;
	while (g_mini.tokens->token_array[index]
		&& ft_strcmp(g_mini.tokens->token_array[index], "|"))
	{
		size++;
		index++;
	}
	return (size + 1);
}
