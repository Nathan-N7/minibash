#include "../libs/minishell.h"
#include "../my_lib/libft.h"
#include "../libs/structs.h"

static int get_index(char **envp, char *key)
{
    int i;
    int len;

    len = 0;
    while (key[len] && key[len] != '=')
        len++;
    i = -1;
    while (envp[++i])
        if(ft_strncmp(envp[i], key, len) == 0 && envp[i][len] == '=')
            return (i);
    return (-1);
}

char    **new_envp(char **envp, char *arg)
{
    int     i;
    char    **envp_new;

    i = get_index(envp, arg);
    if (i >= 0)
    {
        free(envp[i]);
        envp[i] = ft_strdup(arg);
        return (envp);
    }
    i = -1;
    while (envp[++i])
        ;
    envp_new = malloc(sizeof(char *) * (i + 2));
    if (!envp_new)
        return (NULL);
    i = -1;
    while (envp[++i])
        envp_new[i] = envp[i];
    envp_new[i++] = ft_strdup(arg);
    envp_new[i] = NULL;
    free(envp);
    return (envp_new);
}

int verify_var(char *str)
{
    int i;

    i = 0;
    if (!str || !str[0])
        return (0);
    if (!ft_isalpha(str[0]) && str[0] != '_')
        return (0);
    while (str[i] && str[i] != '=')
    {
        if (!ft_isalnum(str[i]) && str[i] != '_')
            return (0);
        i++;
    }
    return (1);
}

int    ft_export(char **args, t_envp *env)
{
    int     i;
    char    **tmp;

    i = -1;
    if (!args[1])
    {
        while (env->envp[++i])
            printf("declare -x %s\n", env->envp[i]);
        return (0);
    }
    while (args[++i])
    {
        if (!verify_var(args[i]))
        {
            printf("export: `%s`: not a valid identifier\n", args[i]);
            return (1);
        }
        if (ft_strchr(args[i], '='))
        {
            tmp = new_envp(env->envp, args[i]);
            if (!tmp)
                return (1);
            env->envp = tmp;
        }
    }
    return (0);
}