#ifndef MINISHELL_H
# define MINISHELL_H

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

#endif