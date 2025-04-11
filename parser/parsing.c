#include "../libs/minishell.h"
#include "../mylib/libft.h"
#include "../libs/structs.h"

int verify_aspas(char   *r)
{
    int i;
    int c;

    i = -1;
    c = 0;
    while (r[++i])
    {
        if (r[i] == '"' && c++)
        {
            while (r[++i] != '"' && r[i])
                continue ;
            if (r[i] == '"')
                c++;
        }
        else if (r[i] == '\'' && c++)
        {
            while (r[++i] != '\'' && r[i])
                continue ;
            if (r[i] == '\'')
                c++;
        }
    }
    return (c);
}

t_command    *parsing(char *input)
{   
    char        *r;
    t_command   *token;

    r = ft_strtrim(input, " \t\n\v\r\f");
    if (!r)
        return (free(r), NULL);
    if (verify_aspas(r) % 2 != 0)
        return (printf("error\n"), NULL);
    token = tokenize(r);
    printf("%s\n", r);
    return (NULL);
}