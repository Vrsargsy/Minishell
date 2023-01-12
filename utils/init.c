/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:19:30 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 07:46:39 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*new_node(char *value, t_env *next)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = next;
	return (new);
}

static int	init_env(t_env **mini_env, char **env)
{
	t_env	*environment;
	int		i;

	i = 0;
	environment = new_node(ft_strdup(env[i++]), NULL);
	if (!environment)
		return (-1);
	*mini_env = environment;
	while (env[i] && mini_env)
	{
		environment->next = new_node(ft_strdup(env[i++]), NULL);
		environment = environment->next;
	}
	return (0);
}

int	init(t_mini *mini, char **env)
{
	mini->status = 0;
	mini->cmd_count = 0;
	if (init_env(&mini->env, env) == -1)
		return (-1);
	increment_shell_level(mini->env);
	return (0);
}
