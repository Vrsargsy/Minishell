/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:13:19 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 08:21:07 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	tok_arr_init(char *line)
{
	int	num;

	num = ft_tok_num(line) + 1;
	g_mini.tokens->size = 0;
	g_mini.tokens->token_array = (char **)malloc(sizeof(char *) * num);
	g_mini.tokens->quote_array = (char **)malloc(sizeof(char *) * num);
}

static void	add_token(char *token, char *quote)
{
	int	index;

	index = g_mini.tokens->size;
	g_mini.tokens->token_array[index] = token;
	g_mini.tokens->quote_array[index] = quote;
	g_mini.tokens->size++;
}

void	get_tokens(char *line)
{
	int			i;
	char		*token;	
	char		*quote;	

	i = 0;
	g_mini.tokens = ft_calloc(1, sizeof(t_token));
	if (line)
		tok_arr_init(line);
	else
		return ;
	while (line[i])
	{
		i += extract_token(&line[i], &token, &quote);
		if (token != NULL && quote != NULL)
			add_token(token, quote);
	}
	add_token(NULL, NULL);
}
