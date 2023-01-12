/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:18:47 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 07:35:44 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_count_commands(char **tok_arr)
{
	int	i;
	int	c;

	if (!tok_arr)
		return (0);
	i = 0;
	c = 1;
	while (tok_arr[i])
	{
		if (tok_arr[i][0] == '|' && tok_arr[i][1] == '\0')
			c++;
		i++;
	}
	return (c);
}
