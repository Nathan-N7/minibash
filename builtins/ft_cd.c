#include "../libs/minishell.h"
#include "../my_lib/libft.h"
#include "../libs/structs.h"

#include <unistd.h>    // chdir, getcwd
#include <stdio.h>     // perror, printf
#include <stdlib.h>    // getenv, malloc, free
#include <string.h>    // strcmp (ou sua libft)

int ft_cd(char *path)
{
    char    *home;

    if (!path || ft_strcmp(path, "~") == 0)
    {
        home = getenv("HOME");
        if (!home)
            return (printf("cd: HOME not set\n"), 1);
        path = home;
    }
    if (chdir(path) != 0)
        return (perror("cd"), 1);
    return (0);
}
