/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:07:55 by natrodri          #+#    #+#             */
/*   Updated: 2025/05/27 19:11:50 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAX_ARGS 512
# define MAX_REDIRS 32
# define TRUE 1
# define FALSE 0

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <signal.h>
# include <errno.h>
# include <limits.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "structs.h"
# include "ft_printf.h"
# include "../my_lib/libft.h"

char        **clone_env(char **envp);
t_command	*parsing(char *input, t_envp *env);
t_token		*tokenize(char *input);
int			ft_isspace(char c);
char		*strip_aspas(char *str);
void		free_tokens(t_token *head);
int			verify_aspas(char *r);
t_command	*new_command(t_command **head);
int			print_error(char *msg);
int	        handle_word(t_command *cmd, t_token *tok, int *c, t_envp *env);
int			handle_redir(t_command *cmd, t_token **tok);
int			handle_pipe(t_command **cmd, int *count);
void		free_commands(t_command *cmd);
char		*get_value(char *name, char **envp);
char	    *expand_var(char *src, t_envp *env);
void	    my_pipe(t_command *cmd, t_envp *env);
int         is_builtin(t_command *cmd);
void	    error_pipe(char *join, t_op	op);
int         ft_pwd();
int         ft_env(t_envp *env);
int         ft_echo(char **arg);
int         get_index(char **envp, char *key);
int         ft_cd(char *path, t_envp *env);
int         ft_export(char **args, t_envp *env);
int         ft_unset(char **args, t_envp *env);
int         builtin_father(t_command *cmd);
int         isdirectory(const char *pathname);
void        handle_heredoc(t_redirect *redir, t_envp *env);
void        handle_append(t_redirect *redir, int *error_flag, char **envp);
void        handle_redin(t_redirect *redir, int *error_flag, char **envp);
char        *create_pathname(const char *filename, char **envp);
int         handle_redirects(t_command *cmd, t_envp *env);
void        handle_redout(t_redirect *redir, int *error_flag, char **envp);
int	        execute_builtin(t_envp *env, t_command *cmd);
void	    free_env(char **envp);

#endif
