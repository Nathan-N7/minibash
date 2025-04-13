/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:13:01 by natrodri          #+#    #+#             */
/*   Updated: 2024/10/01 13:04:52 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char *src, size_t size)
{
	size_t	i;
	int		k;

	k = 0;
	i = 0;
	while (src[k] != '\0')
		k++;
	if (size == 0)
		return (k);
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (k);
}

/*#include <stdio.h>
#include <bsd/string.h>

int	main()
{
	printf("%zu", ft_strlcpy("", "vamos testar", 8));
	printf("%zu", strlcpy("", "vamos testar", 8));
}*/
