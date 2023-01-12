/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:12:03 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 05:52:28 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	read_hd(t_heredoc *t_hd, t_cmd *cmd)
{
	char	*hd_ln;
	int		k;

	k = t_hd->heredocs;
	hd_ln = readline("> ");
	if (hd_ln == NULL)
		return (1);
	else if (!ft_strcmp(hd_ln, t_hd->heredoc))
	{
		free(hd_ln);
		if (t_hd->j == ft_matrixlen(cmd->heredoc))
			close(t_hd->w_ends[k]);
		return (1);
	}
	if (t_hd->refined)
		hd_ln = ft_refine_line(hd_ln);
	if (t_hd->j == ft_matrixlen(cmd->heredoc))
	{
		ft_putstr_fd(hd_ln, t_hd->w_ends[k]);
		ft_putstr_fd("\n", t_hd->w_ends[k]);
	}
	free(hd_ln);
	return (0);
}

static void	get_hd(t_heredoc *t_hd, t_cmd *cmd)
{
	int	br;

	if (cmd->heredoc)
	{
		t_hd->j = 0;
		while (t_hd->j < ft_matrixlen(cmd->heredoc))
		{
			t_hd->refined = 1;
			if (!ft_strcmp(cmd->refine[t_hd->j], "\'")
				&& t_hd->j == ft_matrixlen(cmd->heredoc) - 1)
				t_hd->refined = 0;
			t_hd->heredoc = cmd->heredoc[t_hd->j];
			t_hd->j++;
			while (1)
			{
				br = read_hd(t_hd, cmd);
				if (br)
					break ;
			}
		}
	}
}

void	process_heredoc(t_heredoc *t_hd)
{
	int	i;

	i = 0;
	sig_heredoc();
	while (i < g_mini.cmd_count)
	{
		if (g_mini.commands[i].heredoc)
			get_hd(t_hd, &g_mini.commands[i]);
		t_hd->heredocs++;
		i++;
	}
	exit(0);
}
