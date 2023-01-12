/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:09:12 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 08:19:59 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_get_all_env(const char *var)
{
	t_env	*head;
	int		var_len;
	char	*id;

	head = g_mini.env;
	id = ft_sep_identifier((char *) var);
	var_len = ft_strlen(id);
	if (!ft_is_valid_id(id))
	{
		free(id);
		return (NULL);
	}
	while (head != NULL)
	{
		if (!ft_strncmp(head->value, id, var_len)
			&& (head->value[var_len] == '='
				|| head->value[var_len] == '\0'))
		{
			free(id);
			return (head->value);
		}
		head = head->next;
	}
	free(id);
	return (NULL);
}

char	*ft_getenv(char *var)
{
	char	*env;

	env = ft_get_all_env(var);
	if (env)
		return (env + ft_strlen(var) + 1);
	return (NULL);
}
