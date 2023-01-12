/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:15:19 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 07:29:59 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_mini	g_mini;

int	main(int argc, char **argv, char **env)
{
	char	*line;

	(void) argc;
	(void) argv;
	init(&g_mini, env);
	sig_init();
	while (1)
	{
		line = readline("\033[0;36m\033[1mminishell ▸ \033[0m");
		if (!line)
		{
			ft_putstr_fd("minishell: exit\n", STDERR);
			return (SUCCESS);
		}
		parse_and_execute(line);
		if (ft_strcmp(line, ""))
			add_history(line);
		free(line);
	}
	return (SUCCESS);
}
