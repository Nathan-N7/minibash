/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:46:39 by natrodri          #+#    #+#             */
/*   Updated: 2024/10/11 16:42:07 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	//size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	//i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!dest || !src)
		return (NULL);
	if (d > s)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
		ft_memcpy(d, s, n);
	return (d);
}

/*#include <stdio.h>
#include <string.h>
int	main()
{
	char	str1[] = "abc";
	//char	*s = ft_memmove(str1 + 2, str1, 4);
	char	*p = ft_memmove(str1 + 2, str1, 3);
	char	*k = ft_memcpy(str1 + 2, str1, 3);
	printf("%s\n", p);
	printf("%s\n", k);
}*/
