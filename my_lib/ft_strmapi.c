/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:22:11 by natrodri          #+#    #+#             */
/*   Updated: 2024/10/01 13:07:36 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	size_t	lens;

	i = -1;
	lens = 0;
	if (!s || !f)
		return (0);
	while (s[lens] != '\0')
		lens++;
	str = (char *)malloc((lens + 1) * sizeof(char));
	if (!str)
		return (0);
	while (++i < lens)
		str[i] = f(i, s[i]);
	str[i] = '\0';
	return (str);
}

/*char	teste(unsigned int i, char s)
{
	return (i + s);
}
#include <stdio.h>
int	main()
{
	char	*s;

	s = "aa bb cc";
	printf("%s", ft_strmapi(s, teste));
}*/
