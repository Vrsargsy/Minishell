/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:13:03 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 06:16:26 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	var_len_env(char *line)
{
	int	i;

	i = 0;
	if (!(ft_isalpha(line[i]) || line[i] == '_'))
		return (i);
	while (ft_isalnum(line[++i]) || line[i] == '_')
		;
	return (i);
}

static int	treat_dolla_sign(t_refine *r, char *line)
{
	int		var_len;
	char	*env;

	var_len = var_len_env(r->ptr + 1);
	if (var_len)
	{
		env = ft_substr(r->ptr, 1, var_len);
		r->val = ft_strdup(ft_getenv(env));
		free(env);
		r->prefix = ft_substr(line, 0, r->ptr - line);
		r->postfix = ft_strdup(r->ptr + var_len + 1);
	}
	else if (*(r->ptr + 1) == '?')
	{
		r->val = ft_itoa(g_mini.status);
		r->prefix = ft_substr(line, 0, r->ptr - line);
		r->postfix = ft_strdup(r->ptr + 2);
	}
	else
	{
		r->ptr++;
		r->ptr = ft_strchr(r->ptr, '$');
		return (1);
	}
	return (0);
}

char	*ft_refine_line(char *line)
{
	t_refine	r;

	if (!line)
		return (NULL);
	r.ptr = ft_strchr(line, '$');
	while (r.ptr && *r.ptr)
	{
		if (treat_dolla_sign(&r, line))
			continue ;
		if (r.val)
			r.ptr = ft_strjoin3(r.prefix, r.val, r.postfix);
		else
			r.ptr = ft_strjoin(r.prefix, r.postfix);
		free(line);
		line = r.ptr;
		r.ptr += ft_strlen(r.prefix) + ft_strlen(r.val);
		free(r.prefix);
		free(r.postfix);
		free(r.val);
		r.ptr = ft_strchr(r.ptr, '$');
	}
	return (line);
}

void	ft_append_token(char **token, char *line, int len, int exp)
{
	char	*str;

	str = ft_substr(line, 0, len);
	if (exp)
	{
		str = ft_refine_line(str);
		if (!ft_strcmp(str, "$"))
			return ;
		else if (str[0] == '$')
			str = ft_substr(str, 1, ft_strlen(str));
		else if (str[ft_strlen(str) - 1] == '$')
			str = ft_substr(str, 0, ft_strlen(str) - 1);
	}
	*token = ft_strjoin(*token, str);
}
