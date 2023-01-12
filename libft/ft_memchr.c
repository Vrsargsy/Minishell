/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:12:18 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 02:12:19 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	char			*str_val;
	unsigned int	i;

	str_val = (char *)str;
	i = 0;
	while (i < len)
	{
		if (str_val[i] == c)
		{
			return ((void *)(str + i));
		}
		i++;
	}
	return (NULL);
}
