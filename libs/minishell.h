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

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>
# include "structs.h"

t_command	*parsing(char *input, char **envp);
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
void        my_pipe(t_command *cmd, char **envp);

#endif
