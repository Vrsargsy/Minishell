/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:59:57 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/12/23 08:21:07 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <termios.h>
# include <signal.h>
# include <sys/wait.h>
# include <dirent.h>
# include <errno.h>
# include <stdio.h>
# include <limits.h>
# include "readline/readline.h"
# include "readline/history.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define _ECHO 1
# define _CD 2
# define _PWD 3
# define _EXPORT 4
# define _UNSET 5
# define _ENV 6
# define _EXIT 7

# define SUCCESS 0
# define ERROR 1
# define SYNTAX_ERROR 258
# define UNKNOWN_COMMAND 127

typedef struct s_cmd
{
	char	**args;
	int		in;
	int		out;
	int		s;
	char	**heredoc;
	char	**refine;
}				t_cmd;

typedef struct s_token
{
	char	**token_array;
	char	**quote_array;
	int		size;
}				t_token;

typedef struct s_expansion
{
	int	expand;
	int	i;
	int	j;
}				t_expansion;

typedef struct s_env
{
	char			*value;
	struct s_env	*next;
}				t_env;

typedef struct s_refine
{
	char		*ptr;
	char		*prefix;
	char		*postfix;
	char		*val;
}				t_refine;

typedef struct s_heredoc
{
	int		j;
	int		heredocs;
	int		h_pid;
	int		h_status;
	int		*w_ends;
	int		refined;
	char	*heredoc;
}				t_heredoc;

typedef struct s_mini
{
	t_token	*tokens;
	t_env	*env;
	t_cmd	*commands;
	pid_t	*fam;
	int		cmd_count;
	int		status;
}				t_mini;

extern t_mini	g_mini;

int		ft_count_commands(char **token_array);
int		ft_hd_size(char **token_array);
void	ft_free_commands(t_cmd *cmds);
void	ft_free_matrix(char **matrix);
int		ft_convert_builtin(char *builtin);
int		init(t_mini *mini, char **env);
char	**ft_array_copy(char **args);
int		ft_minishell_error(char *msg);
int		ft_matrixlen(char **matrix);
t_cmd	*ft_find_command(pid_t pid);
int		ft_tok_num(char *line);
int		ft_args_size(int index);
void	ft_free_tokens(void);
int		ft_isnum(char *num);
int		ft_isspace(char c);
void	ft_free_fam(void);
int		ft_abs(int nb);
t_env	*new_node(char *value, t_env *next);
void	increment_shell_level(t_env *env);
int		ft_is_valid_id(char *var);
int		ft_is_valid_decl(char *decl);
char	*ft_sep_identifier(char *var);
char	**ft_env_to_mx(t_env *enc);
void	ft_rm_from_env(char *var);
int		ft_in_env(char *var);
void	ft_add_to_env(char *var);
char	*ft_getenv(char *var);
void	ft_print_env(int fd);
void	sig_init(void);
void	sig_default(void);
void	sig_ignore(void);
void	sig_heredoc(void);
void	supress_output(void);
void	reprompt(int sig);
void	sigquit(int sig);
void	interrupt(int sig);
void	parse_and_execute(char *line);
void	get_tokens(char *line);
int		extract_token(char *line, char **token, char **quote);
int		extract_argument(t_cmd *cmd, int *index);
void	ft_append_token(char **token, char *line, int len, int expand);
void	parse_commands(void);
int		check_pipe(char **args, int *index);
char	*ft_refine_line(char *line);
int		launch_heredoc(void);
void	process_heredoc(t_heredoc *h_info);
void	ft_alloc_heredoc(t_cmd *cmd);
void	ft_alloc_refine(t_cmd *cmd);
int		ft_echo(t_cmd *cmd);
int		ft_cd(t_cmd *cmd);
int		ft_pwd(t_cmd *cmd);
int		ft_export_tok_cmd(t_cmd *cmd);
int		ft_unset(t_cmd *cmd);
int		ft_env(t_cmd *cmd);
void	ft_exit(t_cmd *cmd);
void	ft_exec(t_cmd *cmd);

#endif
