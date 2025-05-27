#include "../libs/minishell.h"
#include "../my_lib/libft.h"
#include "../libs/structs.h"

void ft_env(t_envp *env)
{
    int i = 0;

    if (!env || !env->envp)
        return;

    while (env->envp[i])
    {
        printf("%s\n", env->envp[i]);
        i++;
    }
}