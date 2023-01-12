/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_decl.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:09:30 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 08:06:17 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_valid_decl(char *decl)
{
	int		res;
	char	*name;

	name = ft_sep_identifier(decl);
	res = ft_is_valid_id(name);
	free(name);
	return (res);
}
