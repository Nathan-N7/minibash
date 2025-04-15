#include "../libs/minishell.h"
#include "../libs/structs.h"
#include "../my_lib/libft.h"

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