/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:19:21 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 03:19:22 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_minishell_error(char *msg)
{
	ft_putstr_fd(msg, STDERR);
	ft_putstr_fd("\n", STDERR);
	return (1);
}
