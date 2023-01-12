/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:16:03 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 07:33:12 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	change_status(int termed, int status)
{
	int		sig_true;
	t_cmd	*chosen;

	sig_true = 0;
	if (termed == g_mini.fam[g_mini.cmd_count - 1])
	{
		if (!WTERMSIG(status))
			g_mini.status = WEXITSTATUS(status);
		else
		{
			sig_true = 1;
			g_mini.status = WTERMSIG(status) + 128;
		}
	}
	chosen = ft_find_command(termed);
	if (chosen)
	{
		if (chosen->out != 1)
			close(chosen->out);
		if (chosen->in != 0)
			close(chosen->in);
	}
	return (sig_true);
}

static void	block_main_process(void)
{
	int	i;
	int	status;
	int	sig_true;

	i = 0;
	sig_true = 0;
	while (i < g_mini.cmd_count)
	{
		sig_true += change_status(wait(&status), status);
		i++;
	}
	if (sig_true)
	{
		if (g_mini.status == 131)
			ft_putstr_fd("Quit", STDOUT);
		ft_putstr_fd("\n", STDOUT);
	}
}

static void	start_processes(void)
{
	int	i;

	if (g_mini.cmd_count == 1 && g_mini.commands[0].args
		&& ft_convert_builtin(g_mini.commands[0].args[0]))
		ft_exec(&g_mini.commands[0]);
	else
	{
		i = 0;
		while (i < g_mini.cmd_count)
		{
			g_mini.fam[i] = fork();
			if (g_mini.fam[i] == 0)
			{
				if (!g_mini.commands[i].args)
					exit(0);
				sig_default();
				ft_exec(&g_mini.commands[i]);
			}
			i++;
		}
		sig_ignore();
		block_main_process();
		sig_init();
	}
}

void	parse_and_execute(char *line)
{
	get_tokens(line);
	if (!g_mini.tokens->token_array || !g_mini.tokens->token_array[0])
	{
		ft_free_tokens();
		return ;
	}
	parse_commands();
	if (!g_mini.commands || launch_heredoc())
	{
		ft_free_tokens();
		ft_free_commands(g_mini.commands);
		return ;
	}
	g_mini.fam = ft_calloc(g_mini.cmd_count, sizeof(pid_t));
	start_processes();
	ft_free_commands(g_mini.commands);
	ft_free_fam();
	ft_free_tokens();
}
