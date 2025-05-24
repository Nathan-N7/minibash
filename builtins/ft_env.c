#include "../libs/minishell.h"
#include "../my_lib/libft.h"
#include "../libs/structs.h"

int ft_lenenv(const char *env)
{
    int i;

    i = 0;
    while (env[i] && env[i] != '=')
        i++;
    if (env[i] != '=')
        return (0);
    return (i);
}

void    free_env(t_envp *env)
{
    t_envp  *tmp;

    while (env)
    {
        tmp = env->next;
        free(env->key);
        free(env->value);
        free(env);
        env = tmp;
    }
}

t_envp  *new_node(char *envp)
{
    t_envp  *new;
    int     len;

    len = 0;
    len = ft_lenenv(envp);
    new = ft_calloc(1, sizeof(t_envp));
    if (!new)
        return (NULL);
    new->key = ft_substr(envp, 0, len);
    new->value = ft_strdup(envp + len + 1);
    new->next = NULL;
    return (new);
}

t_envp *get_env(char **envp)
{
    t_envp  *head;
    t_envp  *current;
    t_envp  *new;
    int     i;

    i = 0;
    head = NULL;
    while (envp[i])
    {
        new = new_node(envp[i]);
        if (!head)
        {
            head = new;
            current = head;
        }
        else
        {
            current->next = new;
            current = new;
        }
        i++;
    }
    return (head);
}

void    ft_env(char **envp)
{
    t_envp  *env;
    t_envp  *head;

    env = get_env(envp);
    head = env;
    while (env)
    {
        if (env->value)
            printf("%s=%s\n", env->key, env->value);
        env = env->next;
    }
    free_env(head);
}