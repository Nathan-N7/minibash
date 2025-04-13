/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:37:12 by natrodri          #+#    #+#             */
/*   Updated: 2024/10/11 18:27:35 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>
int	main()
{
	char s[] = "nao sei";
	//char	*k;
	//char	*p;

	//p = (int *)memchr((s, 2 + 256, 3) == s + 2);
	//printf("%s", k);
	printf("%s\n", (char *)ft_memchr(s, 'o', 4));
	printf("%s", (char *)memchr(s, 'o', 4));
	return (0);
}*/
