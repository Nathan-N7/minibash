
#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*dest;
	size_t	i;
    size_t  j;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && i < n)
		i++;
	dest = (char *)malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
    j = -1;
	while (++j < i)
		dest[j] = s[j];
	dest[i] = '\0';
	return (dest);
}
