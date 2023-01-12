/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:12:55 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 02:12:56 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str1, int val, size_t len)
{
	size_t				i;
	unsigned char		*str2;

	i = 0;
	str2 = (unsigned char *)str1;
	while (i < len)
	{
		str2[i] = val;
		i++;
	}
	return (str2);
}
