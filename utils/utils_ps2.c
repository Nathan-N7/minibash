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

void    free_commands(t_command *cmd)
{
    t_command *tmp;
    int        i;

    i = -1;
    while (cmd)
    {
        tmp = cmd->next;
        if (cmd->args)
        {
            while (cmd->args[++i])
                free(cmd->args[i]);
            free(cmd->args);
        }
        i = -1;
        while (++i < cmd->redirect_count)
            free(cmd->redirects[i].filename);
        free(cmd->redirects);
        free(cmd);
        cmd = tmp;
    }
}