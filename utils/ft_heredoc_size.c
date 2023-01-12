/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hd_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:18:56 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 03:18:57 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_hd_size(char **tok_mx)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (tok_mx[i])
	{
		if (!ft_strcmp(tok_mx[i], "<<"))
			len++;
		i++;
	}
	return (len);
}
