#include "../libs/minishell.h"
#include "../my_lib/libft.h"
#include "../libs/structs.h"

void    ft_pwd()
{
    char    *pwd;

    pwd = getcwd(NULL, 0);
    if (!pwd)
        return (1);
    printf("%s\n", pwd);
    free(pwd);
    return (0);
}