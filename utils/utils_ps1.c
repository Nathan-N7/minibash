#include "../libs/minishell.h"
#include "../libs/structs.h"
#include "../my_lib/libft.h"

int verify_aspas(char   *r)
{
    int     i;
    char    aspas;

    i = 0;
    aspas = '\0';
    while (r[i])
    {
        if (r[i] == '\'' || r[i] == '"')
        {
            if (aspas == '\0')
                aspas = r[i];
            else if (aspas == r[i])
                aspas = '\0';
        }
        i++;
    }
    if (aspas == '\0')
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
        return (write(2, "\033[1;31m🚨 Error: too many arguments\033[0m\n", 39), 0);
    cmd->args[*c] = strip_quotes(v);
    (*c)++;
    return (1);
}

int handle_redir(t_command *cmd, t_token **tok)
{
    if (!(*tok)->next || (*tok)->next->type != WORD)
        return (write(2, "\033[1;31m🚨 Syntax Error: tokenize\033[0m\n", 39), 0);
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
        return (0);
    (*cmd)->args[*count] = NULL;
    *cmd = new_command(&(*cmd)->next);
    if (!*cmd)
        return (0);
    *count = 0;
    return (1);
}