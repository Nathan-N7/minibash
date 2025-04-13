/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:19:20 by natrodri          #+#    #+#             */
/*   Updated: 2024/10/12 16:02:39 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*s2;

	i = 0;
	s2 = (unsigned char *)s;
	while (s2[i] != '\0')
		i++;
	if (c == '\0')
		return ((char *)&s2[i]);
	while (i > 0 && s2[i] != (char)c)
		i--;
	if (s2[i] == (char)c)
		return ((char *)&s2[i]);
	return (NULL);
}

/*#include <string.h>
#include <stdio.h>
int	main()
{
	printf("%s\n", strrchr("tesando udo", 259));
	printf("%s", ft_strrchr("tesando udo", 259));
}*/
