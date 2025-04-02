#include "../libs/minishell.h"
#include "../libs/my_lib.h"
#include "../libs/structs.h"



static int	count(char const *str, char charset)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] != charset && str[i] != '\0')
		{
			c++;
			while (str[i] != charset && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (c);
}

char    **tokenize(char *input)
{
    char    **tokens;
    int     i;

    i = 0;
    tokens = alocate(input);
    while (input[i])
    {

    }
}