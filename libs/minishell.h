/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:07:55 by natrodri          #+#    #+#             */
/*   Updated: 2025/05/08 16:09:11 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define MAX_ARGS 512
# define MAX_REDIRS 32

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

char        **clone_env(char **envp);
t_command	*parsing(char *input, t_envp *env);
t_token		*tokenize(char *input);
int			ft_isspace(char c);
char		*strip_aspas(char *str);
void		free_tokens(t_token *head);
int			verify_aspas(char *r);
t_command	*new_command(t_command **head);
int			print_error(char *msg);
int			handle_word(t_command *cmd, t_token *tok, int *c, char **envp);
int			handle_redir(t_command *cmd, t_token **tok);
int			handle_pipe(t_command **cmd, int *count);
void		free_commands(t_command *cmd);
char		*get_value(char *name, char **envp);
char		*expand_var(char *v, char **envp);
void	    my_pipe(t_command *cmd, t_envp *env);
int         is_builtin(t_command *cmd);
void	    error_pipe(char *join, t_op	op);
void        ft_pwd();
void        ft_env(t_envp *env);
int         ft_echo(char **arg);
int         ft_cd(char *path);
void        ft_export(char **args, t_envp *env);
int         builtin_father(t_command *cmd);
int         isdirectory(const char *pathname);
void        handle_heredoc(t_redirect *redir);
void        handle_append(t_redirect *redir, char **envp);
void        handle_redin(t_redirect *redir, char **envp);
char        *create_pathname(const char *filename, char **envp);
int         handle_redirects(t_command *cmd, char **envp);
void        handle_redout(t_redirect *redir, char **envp);
void	    execute_builtin(t_envp *env, t_command *cmd);

#endif
