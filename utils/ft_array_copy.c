/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_cpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:18:37 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 03:18:38 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_array_copy(char **args)
{
	char	**cpy;
	int		i;

	i = ft_matrixlen(args) + 1;
	cpy = (char **)malloc(sizeof(char *) * i);
	i = 0;
	while (args[i])
	{
		cpy[i] = ft_strdup(args[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
