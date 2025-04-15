#ifndef MINISHELL_H
# define MINISHELL_H
# define MAX_ARGS 512
# define MAX_REDIRS 32

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "structs.h"

t_command    *parsing(char *input);
t_token	*tokenize(char *input);
int	ft_isspace(char c);
char *strip_quotes(char *str);
void	free_tokens(t_token *head);
int verify_quote(char   *r);
t_command   *new_command(t_command  **head);
int    print_error(char *msg);
int handle_word(t_command *cmd, char *v, int *c);
int handle_redir(t_command *cmd, t_token **tok);
int handle_pipe(t_command **cmd, int *count);

#endif