#include "../libs/minishell.h"
#include "../libs/structs.h"
#include "../mylib/libft.h"


int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}
char *strip_quotes(char *str)
{
	size_t len = 0;
	while (str[len])
		len++;
	if ((str[0] == '"' || str[0] == '\'') && str[len - 1] == str[0])
		return ft_strndup(str + 1, len - 2);
	return ft_strdup(str);
}