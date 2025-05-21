#include "../libs/minishell.h"
#include "../my_lib/libft.h"
#include "../libs/structs.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void    ft_cd(char *path)
{
    char *old;
    char *home;

    old = getcwd(NULL, 0);
    if (!old)
    {
        perror("getcwd");
        return ;
    }
    if (path == NULL || path[0] == '\0')
    {
        home = getenv("HOME");
        if (!home)
        {
            printf("cd: HOME not set\n");
            free(old);
            return ;
        }
        if (chdir(home) < 0)
        {
            perror("cd");
            free(old);
            return ;
        }
    }
    else
    {
        if (chdir(path) < 0)
        {
            printf("cd: no such file or directory: %s\n", path);
            free(old);
            return ;
        }
    }
    free(old);
}


int main(int ac, char **av)
{
    (void)ac;
    ft_cd(av[1]);
}