/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:12:18 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 05:55:39 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	can_be_pipe(int id)
{
	char	*tok;
	char	*next;

	tok = g_mini.tokens->token_array[id];
	next = g_mini.tokens->token_array[id + 1];
	if (tok && !ft_strcmp(tok, "|")
		&& (next != NULL && ft_strcmp(next, "|")))
		return (1);
	return (0);
}

static int	not_can_be_pipe(int id)
{
	char	*tok;
	char	*next;

	tok = g_mini.tokens->token_array[id];
	next = g_mini.tokens->token_array[id + 1];
	if (tok && !ft_strcmp(tok, "|")
		&& (next == NULL || !ft_strcmp(next, "|")))
		return (1);
	return (0);
}

int	check_pipe(char **args, int *id)
{
	if (can_be_pipe(*id))
		*id = *id + 1;
	else if (not_can_be_pipe(*id))
	{
		ft_minishell_error("minishell: syntax error: pipe");
		ft_free_matrix(args);
		g_mini.status = SYNTAX_ERROR;
		return (1);
	}
	return (0);
}
