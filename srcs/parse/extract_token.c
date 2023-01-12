/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:12:47 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 08:02:15 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	treat_pipe_rd(char *line, char **token, t_expansion *exp)
{
	if (exp->i != exp->j || (*token)[0] != '\0')
	{
		ft_append_token(token, &line[exp->i], exp->j - exp->i, exp->expand);
		return (exp->j);
	}
	else
	{
		if (!ft_strncmp(&line[exp->j], "<<", 2) || !ft_strncmp(&line[exp->j],
				">>", 2))
			exp->j++;
		ft_append_token(token, &line[exp->i], exp->j - exp->i + 1, exp->expand);
		return (exp->j + 1);
	}
}

static void	init_token(char *line, char **token, char **quote, t_expansion *exp)
{
	exp->i = 0;
	exp->j = 0;
	exp->expand = 1;
	while (ft_isspace(line[exp->j]))
	{
		exp->i++;
		exp->j++;
	}
	if (line[exp->j])
	{
		*token = ft_strdup("");
		*quote = ft_strdup("");
	}
	else
	{
		*token = NULL;
		*quote = NULL;
	}
}

static int	proc_tok_quote(char *line, char **token, char **quote,
				t_expansion *exp)
{
	char	*tmp;

	tmp = ft_strchr(&line[exp->j + 1], line[exp->j]);
	if (tmp)
	{
		if (!**quote)
			ft_append_token(quote, "\'", 1, 0);
		ft_append_token(token, &line[exp->i], exp->j - exp->i, exp->expand);
		exp->i = exp->j + 1;
		exp->j = (tmp - 1) - line;
		if (line[exp->j + 1] == '\'')
			exp->expand = 0;
		ft_append_token(token, &line[exp->i], exp->j - exp->i + 1, exp->expand);
		exp->expand = 1;
		exp->i = exp->j + 2;
		exp->j = exp->i;
		return (1);
	}
	return (0);
}

static int	proc_tok_char(char *line, char **token, char **quote,
				t_expansion *exp)
{
	int		res;

	if (line[exp->j] != '\'' && line[exp->j] != '\"'
		&& !ft_isspace(line[exp->j + 1]) && line[exp->j + 1])
			;
	else if ((ft_isspace(line[exp->j + 1]) && !(line[exp->j] == '\''
				|| line[exp->j] == '\"')) || !line[exp->j + 1])
		ft_append_token(token, &line[exp->i], exp->j - exp->i + 1, exp->expand);
	else
	{
		res = proc_tok_quote(line, token, quote, exp);
		if (res)
			return (1);
	}
	return (0);
}

int	extract_token(char *line, char **token, char **quote)
{
	t_expansion	exp;
	int			cont;

	init_token(line, token, quote, &exp);
	while (!ft_isspace(line[exp.j]) && line[exp.j])
	{
		if (line[exp.j] == '<' || line[exp.j] == '>' || line[exp.j] == '|')
			return (treat_pipe_rd(line, token, &exp));
		cont = proc_tok_char(line, token, quote, &exp);
		if (cont)
			continue ;
		exp.j++;
	}
	return (exp.j);
}
