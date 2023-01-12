/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:12:39 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 06:02:02 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	treat_heredoc(t_cmd *cmd, int *id)
{
	char	*tok;
	char	*err;

	*id = *id + 1;
	tok = g_mini.tokens->token_array[*id];
	if (tok == NULL || (tok[0] == '|' && tok[1] == '\0')
		|| !ft_strcmp(tok, "<<"))
	{
		if (tok == NULL)
			err = "syntax error near unexpected tok `newline'";
		else
			err = ft_strjoin3("syntax error near unexpected tok `",
					tok, "'");
		ft_minishell_error(ft_strjoin("minishell: ", err));
		g_mini.status = SYNTAX_ERROR;
		return (1);
	}
	if (!cmd->heredoc)
		ft_alloc_heredoc(cmd);
	cmd->heredoc[cmd->s] = ft_strdup(tok);
	if (!cmd->refine)
		ft_alloc_refine(cmd);
	cmd->refine[cmd->s++] = ft_strdup(g_mini.tokens->quote_array[*id]);
	return (0);
}

static int	redir_check(int id)
{
	char	*tok;
	char	*quote;

	tok = g_mini.tokens->token_array[id];
	quote = g_mini.tokens->quote_array[id];
	if (tok == NULL || (tok[0] == '|' && tok[1] == '\0')
		|| (quote && !*quote && (!ft_strcmp(tok, "<<")
				|| !ft_strcmp(tok, ">>")
				|| !ft_strcmp(tok, "<") || !ft_strcmp(tok, ">"))))
		return (1);
	return (0);
}

static int	treat_redirection(int *cmd_fd, int *id, int open_status)
{
	int		fd;
	char	dir;

	dir = g_mini.tokens->token_array[*id][0];
	*id = *id + 1;
	if (redir_check(*id))
	{
		ft_minishell_error("minishell: syntax error: redirection");
		g_mini.status = SYNTAX_ERROR;
		return (1);
	}
	if ((dir == '>' && *cmd_fd != 1) || (dir == '<' && *cmd_fd != 0))
		close(*cmd_fd);
	fd = open(g_mini.tokens->token_array[*id], open_status, 0644);
	if (fd == -1)
	{
		perror("minishell: Faild to open a file");
		g_mini.status = 1;
		return (1);
	}
	*cmd_fd = fd;
	return (0);
}

static int	treat_tok(t_cmd *cmd, char ***args, int *id, int *i)
{
	int		err;
	char	*tok;

	err = 0;
	tok = g_mini.tokens->token_array[*id];
	if (!ft_strcmp(tok, "<<"))
		err = treat_heredoc(cmd, id);
	else if (!ft_strcmp(tok, ">"))
		err = treat_redirection(&(cmd->out), id,
				O_TRUNC | O_WRONLY | O_CREAT);
	else if (!ft_strcmp(tok, ">>"))
		err = treat_redirection(&(cmd->out), id,
				O_APPEND | O_WRONLY | O_CREAT);
	else if (!ft_strcmp(tok, "<"))
		err = treat_redirection(&(cmd->in), id, O_RDONLY);
	else
	{
		(*args)[*i] = ft_strdup(tok);
		*i = *i + 1;
	}
	return (err);
}

int	extract_argument(t_cmd *cmd, int *id)
{
	char	**args;
	int		i;

	args = ft_calloc(ft_args_size(*id), sizeof(char *));
	i = 0;
	while (g_mini.tokens->token_array[*id]
		&& ft_strcmp(g_mini.tokens->token_array[*id], "|" ))
	{
		if (treat_tok(cmd, &args, id, &i))
		{
			ft_free_matrix(args);
			return (1);
		}
		*id = *id + 1;
	}
	if (check_pipe(args, id))
		return (1);
	if (ft_matrixlen(args) > 0)
	{	
		cmd->args = ft_array_copy(args);
		ft_free_matrix(args);
	}
	return (0);
}
