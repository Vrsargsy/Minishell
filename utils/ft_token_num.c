/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tok_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:19:26 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 03:19:27 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	add_len(char *tok)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tok[i])
	{
		if (tok[i] == '|')
			count += 2;
		else if (tok[i] == '>')
		{
			if (tok[i + 1] && tok[i + 1] == '>')
				i += 2;
			count += 2;
		}
		else if (tok[i] == '<')
		{
			if (tok[i + 1] && tok[i + 1] == '<')
				i += 2;
			count += 2;
		}
		i++;
	}
	return (count + 1);
}

int	ft_tok_num(char *line)
{
	char	**toks;
	int		i;
	int		len;

	i = 0;
	len = 0;
	toks = ft_split(line, ' ');
	while (toks[i])
	{
		len += add_len(toks[i]);
		i++;
	}
	ft_free_matrix(toks);
	return (len);
}
