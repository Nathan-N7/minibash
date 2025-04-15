#include "../libs/minishell.h"
#include "../libs/structs.h"
#include "../my_lib/libft.h"

int verify_quote(char   *r)
{
    int     i;
    char    quote;

    i = 0;
    quote = '\0';
    while (r[i])
    {
        if (r[i] == '\'' || r[i] == '"')
        {
            if (quote == '\0')
                quote = r[i];
            else if (quote == r[i])
                quote = '\0';
        }
        i++;
    }
    if (quote == '\0')
        return (1);
    else
        return (0);
}

int    print_error(char *msg)
{
    write(2, msg, ft_strlen(msg));
    return (0);
}

int handle_word(t_command *cmd, char *v, int *c)
{
    if (*c + 1 >= MAX_ARGS -1)
        return (print_error("Error: too many arguments"));
    cmd->args[*c] = strip_quotes(v);
    (*c)++;
    return (1);
}

int handle_redir(t_command *cmd, t_token **tok)
{
    if (!(*tok)->next || (*tok)->next->type != WORD)
        return (print_error("Syntax Error"));
    if (cmd->redirect_count >= MAX_REDIRS)
        return (print_error("Error"));
    cmd->redirects[cmd->redirect_count].type = (*tok)->type;
    cmd->redirects[cmd->redirect_count].filename = ft_strdup((*tok)->next->value);
    cmd->redirect_count++;
    *tok = (*tok)->next;
    return (1);
}

int handle_pipe(t_command **cmd, int *count)
{
    if (!(*cmd)->args || !(*cmd)->args[0])
        return (print_error("Syntax Error"));
    (*cmd)->args[*count] = NULL;
    *cmd = new_command(&(*cmd)->next);
    if (!*cmd)
        return (0);
    *count = 0;
    return (1);
}