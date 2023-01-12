/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:12:24 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 02:12:25 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	const unsigned char	*str1_val;
	const unsigned char	*str2_val;
	size_t				i;

	str1_val = (const unsigned char *)str1;
	str2_val = (const unsigned char *)str2;
	i = 0;
	while (i < len)
	{
		if (str1_val[i] != str2_val[i])
		{
			return (str1_val[i] - str2_val[i]);
		}
		i++;
	}
	return (0);
}
