#include "../libs/minishell.h"
#include "../libs/structs.h"
#include "../my_lib/libft.h"

char	*get_value(char *name, char **envp)
{
	int	i;
	int	j;
	int	len;
	char	result[4096];

	i = 0;
	len = ft_strlen(name);
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], name, len) && envp[i][len] == '=')
		{
			j = len;
			len = 0;
			while (envp[i][j])
				result[len++] = envp[i][++j];
			result[len] = '\0';
			return (ft_strdup(result));
		}
		i++;
	}
	return (ft_strdup(""));
}

char	*expand_var(char *src, char **envp)
{
    char buffer[4096];
    char varname[256];
    int i = 0;
	int j = 0;

    while (src[i])
	{
        if (src[i] == '\'')
		{
            i++;
            while (src[i] && src[i] != '\'')
                buffer[j++] = src[i++];
            if (src[i] == '\'')
				i++;
        }
        else if (src[i] == '\"')
		{
            i++;
            while (src[i] && src[i] != '\"') {
                if (src[i] == '$' && ft_isalnum(src[i+1])) {
                    int k = 0;
                    i++;
                    while (src[i] && (ft_isalnum(src[i]) || src[i]=='_'))
                        varname[k++] = src[i++];
                    varname[k] = '\0';
                    char *val = get_value(varname, envp);
                    for (int m = 0; val[m]; m++)
                        buffer[j++] = val[m];
                    free(val);
                } else
                    buffer[j++] = src[i++];
            }
            if (src[i] == '\"')
				i++;
        }
        else if (src[i] == '$' && ft_isalnum(src[i+1]))
		{

            int k = 0;
            i++;
            while (src[i] && (ft_isalnum(src[i]) || src[i]=='_'))
                varname[k++] = src[i++];
            varname[k] = '\0';
            char *val = get_value(varname, envp);
            for (int m = 0; val[m]; m++)
                buffer[j++] = val[m];
            free(val);
        }
        else
            buffer[j++] = src[i++];
    }
    buffer[j] = '\0';
    return ft_strdup(buffer);
}
