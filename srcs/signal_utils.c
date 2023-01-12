/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:16:28 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 13:57:32 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	suppress_output(void)
{
	struct termios	termios_p;

	if (tcgetattr(0, &termios_p))
		perror("minishell: tcgetattr");
	termios_p.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, 0, &termios_p))
		perror("minishell: tcsetattr");
}

void	reprompt(int sig)
{
	(void)sig;
	suppress_output();
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	sigquit(int sig)
{
	(void)sig;
	suppress_output();
	rl_on_new_line();
	rl_redisplay();
}

void	interrupt(int sig)
{
	(void)sig;
	suppress_output();
	rl_on_new_line();
	rl_redisplay();
	exit(1);
}
