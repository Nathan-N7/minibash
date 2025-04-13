/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:40:41 by natrodri          #+#    #+#             */
/*   Updated: 2024/10/11 17:17:52 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lend;
	size_t	lens;
	size_t	i;
	size_t	cpy;

	lend = 0;
	lens = ft_strlen(src);
	cpy = 0;
	while (dst[lend] != '\0' && lend < size)
		lend++;
	if (lend >= size)
		return (lend + lens);
	cpy = size - lend - 1;
	if (cpy > lens)
		cpy = lens;
	i = 0;
	while (i < cpy)
	{
		dst[lend + i] = src[i];
		i++;
	}
	dst[lend + cpy] = '\0';
	return (lend + lens);
}
/*#include <stdio.h>
#include <bsd/string.h>
int	main()
{
	char	str[] = "Hello, ";
	char	stg[] = "Good";
	char	s2[] = "Hello, ";
	char	s3[] = "Good";
	printf("%zu\n", ft_strlcat(str, stg, 3));
	printf("%zu", strlcat(s2, s3, 3));
}*/
