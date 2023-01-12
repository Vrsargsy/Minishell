/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:10:55 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 08:17:41 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_alloc_refine(t_cmd *cmd)
{
	int	size;

	size = ft_hd_size(g_mini.tokens->token_array) + 1;
	cmd->refine = ft_calloc(size, sizeof(char *));
}

void	ft_alloc_heredoc(t_cmd *cmd)
{
	int	size;

	size = ft_hd_size(g_mini.tokens->token_array) + 1;
	cmd->heredoc = ft_calloc(size, sizeof(char *));
}
