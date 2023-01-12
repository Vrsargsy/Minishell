/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:11:13 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 05:45:46 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	init_wr_end(t_heredoc *hd, int i, int *j)
{
	int	pipefd[2];

	if (g_mini.commands[i].heredoc)
	{
		pipe(pipefd);
		if (g_mini.commands[i].in != 0)
			close(g_mini.commands[i].in);
		g_mini.commands[i].in = pipefd[0];
		hd->w_ends[(*j)++] = pipefd[1];
	}
}

static int	save_write_ends(t_heredoc *hd)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	j = 0;
	cnt = 0;
	while (i < g_mini.cmd_count)
		if (g_mini.commands[i++].heredoc)
			cnt++;
	hd->w_ends = malloc(cnt * sizeof(int *));
	i = 0;
	while (i < g_mini.cmd_count)
	{
		init_wr_end(hd, i, &j);
		i++;
	}
	return (cnt);
}

static int	init_hd(t_heredoc *hd)
{
	int	i;

	hd->w_ends = NULL;
	hd->heredocs = save_write_ends(hd);
	if (!hd->w_ends)
		return (1);
	sig_ignore();
	hd->h_pid = fork();
	i = 0;
	while (hd->h_pid && i < hd->heredocs)
		close(hd->w_ends[i++]);
	hd->heredocs = 0;
	return (0);
}

int	launch_heredoc(void)
{
	t_heredoc	hd;

	if (init_hd(&hd))
		return (0);
	if (hd.h_pid == 0)
		process_heredoc(&hd);
	wait(&(hd.h_status));
	free(hd.w_ends);
	sig_init();
	if (WEXITSTATUS(hd.h_status) == 1)
	{
		g_mini.status = 130;
		ft_putstr_fd("\n", STDOUT);
		return (1);
	}
	return (0);
}
