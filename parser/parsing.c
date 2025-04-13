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
    t_token   *tokens;

    r = ft_strtrim(input, " \t\n\v\r\f");
    if (!r)
        return (free(r), NULL);
    if (verify_aspas(r) % 2 != 0)
        return (printf("error\n"), NULL);
    tokens = tokenize(r);
    t_token *tmp = tokens;
    while (tmp)
    {
        printf("TOKEN: type=%d, value=%s\n", tmp->type, tmp->value);
        tmp = tmp->next;
    }
    return (NULL);
}