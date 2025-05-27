/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:55:30 by natrodri          #+#    #+#             */
/*   Updated: 2025/05/08 15:24:59 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minishell.h"
#include "../my_lib/libft.h"
#include "../libs/structs.h"

/*void	print_commands(t_command *cmds)
{
	int	i;
	int	j;

	i = 1;
	while (cmds)
	{
		j = 0;
		printf("-- Command %d:\n", i++);
		while (cmds->args && cmds->args[j])
		{
			printf("    Arg[%d]: %s\n", j, cmds->args[j]);
			j++;
		}
		j = 0;
		while (j < cmds->redirect_count)
		{
			const char *redir_type[] = { "WORD", "PIPE", "<", ">", ">>", "<<" };
			printf("-> Redirect: type=%s, file=%s\n",
				redir_type[cmds->redirects[j].type],
				cmds->redirects[j].filename);
			j++;
		}
		cmds = cmds->next;
	}
}

void	print_tokens(t_token *tokens)
{
	t_token *tmp = tokens;
    while (tmp)
    {
        printf("TOKEN: type=%d, value=%s\n", tmp->type, tmp->value);
        tmp = tmp->next;
    }
}*/

int	init_redir(t_command *cmd)
{
	int	i;

	if (cmd->redirect_count == 0)
		return (0);
	i = 0;
	while (i < cmd->redirect_count)
	{
		if (cmd->redirects[i].type != REDIR_OUT
			&& cmd->redirects[i].type != APPEND)
			return (0);
		i++;
	}
	return (1);
}

t_command	*new_command(t_command **head)
{
	t_command	*new;

	new = ft_calloc(1, sizeof(t_command));
	if (!new)
		return (NULL);
	new->args = ft_calloc(MAX_ARGS, sizeof(char *));
	if (!new->args)
		return (NULL);
	new->redirects = ft_calloc(MAX_REDIRS, sizeof(t_redirect));
	if (!*head)
		*head = new;
	return (new);
}

int	parse_token2(t_command **cmd, t_token **tok, int *c, char **envp)
{
	if ((*tok)->type == WORD)
		handle_word(*cmd, *tok, c, envp);
	else if ((*tok)->type == REDIR_IN || (*tok)->type == REDIR_OUT
		|| (*tok)->type == APPEND || (*tok)->type == HEREDOC)
	{
		if (!handle_redir(*cmd, tok))
			return (0);
	}
	else if ((*tok)->type == PIPE)
	{
		if (!handle_pipe(cmd, c))
			return (0);
	}
	return (1);
}

t_command	*parse_tokens(t_token *tokens, char **envp)
{
	t_command	*head;
	t_command	*current;
	t_token		*tok;
	int			count;

	head = NULL;
	current = NULL;
	tok = tokens;
	count = 0;
	while (tok)
	{
		if (!current)
		{
			current = new_command(&head);
			if (!current)
				return (free_commands(head), NULL);
		}
		if (!parse_token2(&current, &tok, &count, envp))
			return (free_commands(head), NULL);
		tok = tok->next;
	}
	if (!current || (current->redirect_count == 0 && !current->args[0]))
		return (free_commands(head),
			write(2, "\033[1;31m🚨 Syntax Error: tokenize\033[0m\n", 39), NULL);
	return (current->args[count] = NULL, head);
}

t_command	*parsing(char *input, t_envp *env)
{
	char		*r;
	t_token		*tokens;
	t_command	*commands;
	char		**envp;

	r = ft_strtrim(input, " \t\n\v\r\f");
	envp = env->envp;
	if (!r || r[0] == '\0')
		return (free(r), NULL);
	if (!verify_aspas(r))
	{
		free(r);
		write(2, "\033[1;31m🚨 Syntax Error: Aspas\033[0m\n", 36);
		exit (0);
	}
	tokens = tokenize(r);
	commands = parse_tokens(tokens, envp);
	/*if (commands)
		print_commands(commands);
	print_tokens(tokens);*/
	free(r);
	free_tokens(tokens);
	return (commands);
}