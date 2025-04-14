#include "../libs/minishell.h"
#include "../libs/structs.h"
#include "../my_lib/libft.h"

int verify_aspas(char   *r)
{
    int i;
    int c;

    i = -1;
    c = 0;
    while (r[++i])
    {
        if (r[i] == '"' && c++)
        {
            while (r[++i] != '"' && r[i])
                continue ;
            if (r[i] == '"')
                c++;
        }
        else if (r[i] == '\'' && c++)
        {
            while (r[++i] != '\'' && r[i])
                continue ;
            if (r[i] == '\'')
                c++;
        }
    }
    return (c);
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
    cmd->args[*c] = ft_strdup(v);
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