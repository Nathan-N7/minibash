#include "../libs/my_lib.h"

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