#include "../libs/minishell.h"
#include "../mylib/libft.h"
#include "../libs/structs.h"
//gcc minishell.c -lreadline -lhistory
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

int main(int ac, char **av)
{
    char    *input;
    t_command   *root;

    (void)av;
    if (ac != 1)
    {
        printf("Error");
        return (0);
    }
    while (1)
    {
        input = readline("\033[1;35m~sush$>\033[0m ");
        if (!input || ft_strcmp(input, "exit") == 0)
             break;
        if (*input)
            add_history(input);
        root = parsing(input);
        free(root);
        free (input);
    }
    return (0);
}
