#include "../libs/minishell.h"
#include "../my_lib/libft.h"
#include "../libs/structs.h"

int ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned char	*s;

	s = (unsigned char *)s1;
	i = 0;
	while (s[i] && s2[i] && s[i] == s2[i])
	{
		i++;
	}
	return (s[i] - s2[i]);
}

int main(int ac, char **av, char **envp)
{
    char        *input;
    t_command   *root;

    (void)av;
    if (ac != 1)
        return (write(2, "\033[1;31m🚨 Error: initialization failure\033[0m\n", 45), 0);
    while (1)
    {
        input = readline("\033[1;35m~sush$>\033[0m ");
        if (!input || ft_strcmp(input, "exit") == 0)
        {
            free(input);
            break;
        }
        if (*input)
            add_history(input);
        root = parsing(input, envp);
        free_commands(root);
        free (input);
    }
    rl_clear_history();
    return (0);
}
