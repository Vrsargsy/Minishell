/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_id.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:10:05 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 05:39:43 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_valid_id(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (!(ft_isalpha(str[i]) || str[i] == '_') || str[i] == '=')
		return (0);
	i++;
	while (str[i])
	{
		if (!(ft_isalnum(str[i]) || str[i] == '_') || str[i] == '=')
			return (0);
		i++;
	}
	return (1);
}
