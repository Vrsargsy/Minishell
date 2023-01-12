/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sep_identifier.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:10:38 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 05:41:08 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_sep_identifier(char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	res = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (str[i] && str[i] != '=')
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}
