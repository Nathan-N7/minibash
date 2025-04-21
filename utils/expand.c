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

char	*expand_var(char *v, char **envp)
{
	char	buffer[4096];
	char	varname[256];
	char	*val;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (v[i])
	{
		if (v[i] == '$' && ft_isalnum(v[i + 1]))
		{
			i++;
			k = 0;
			while (v[i] && (ft_isalnum(v[i]) || v[i] == '_'))
				varname[k++] = v[i++];
			varname[k] = '\0';
			val = get_value(varname, envp);
			k = 0;
			while (val[k])
				buffer[j++] = val[k++];
			free(val);
		}
		else
			buffer[j++] = v[i++];
	}
	buffer[j] = '\0';
	return (ft_strdup(buffer));
}
