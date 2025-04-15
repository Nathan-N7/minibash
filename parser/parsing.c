#include "../libs/minishell.h"
#include "../my_lib/libft.h"
#include "../libs/structs.h"

void	print_commands(t_command *cmds)
{
	int	i = 1;
	int	j;

	while (cmds)
	{
		printf("📦 Command %d:\n", i++);
		for (j = 0; cmds->args && cmds->args[j]; j++)
			printf("  🔹 Arg[%d]: %s\n", j, cmds->args[j]);
		for (j = 0; j < cmds->redirect_count; j++)
		{
			const char *redir_type[] = { "WORD", "PIPE", "<", ">", ">>", "<<" };
			printf("  🔁 Redirect: type=%s, file=%s\n",
				redir_type[cmds->redirects[j].type],
				cmds->redirects[j].filename);
		}
		cmds = cmds->next;
	}
}

t_command   *new_command(t_command  **head)
{
    t_command   *new;

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

int parse_token2(t_command  **cmd, t_token  **tok, int  *c)
{
    if ((*tok)->type == WORD)
        handle_word(*cmd, (*tok)->value, c);
    else if ((*tok)->type == REDIR_IN || (*tok)->type == REDIR_OUT || (*tok)->type == APPEND || (*tok)->type == HEREDOC)
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

t_command   *parse_tokens(t_token *tokens)
{
    t_command   *head;
    t_command   *current;
    t_token     *tok;
    int         count;

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
                return (NULL);
        }
        if (!parse_token2(&current, &tok, &count))
            return (NULL);
        tok = tok->next;
    }
    if (!current || !current->args || !current->args[0])
        return (printf("error"), NULL);
    current->args[count] = NULL;
    return (head);
}

t_command    *parsing(char *input)
{   
    char        *r;
    t_token     *tokens;
    t_command   *commands;

    r = ft_strtrim(input, " \t\n\v\r\f");
    if (!r)
        return (free(r), NULL);
    if (!verify_quote(r))
        return (free(r), printf("Error Sintax\n"), NULL);
    tokens = tokenize(r);
    //t_token *tmp = tokens;
    /*while (tmp)
    {
        printf("TOKEN: type=%d, value=%s\n", tmp->type, tmp->value);
        tmp = tmp->next;
    }*/
    commands = parse_tokens(tokens);
    if (!commands)
        printf("retornou NULL\n");
    else
        print_commands(commands);
    free(r);
    free_tokens(tokens);
    return (commands);
}