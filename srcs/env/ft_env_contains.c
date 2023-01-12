/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:01:19 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 05:28:06 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_in_env(char *str)
{
	char	*result;
	char	*name;

	name = ft_sep_identifier(str);
	result = ft_getenv(name);
	free(name);
	if (result)
		return (1);
	return (0);
}
