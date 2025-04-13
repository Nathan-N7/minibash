/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:49:15 by natrodri          #+#    #+#             */
/*   Updated: 2024/10/01 13:08:41 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (little[k] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		k = 0;
		while ((big[i + k] == little[k] || little[k] == '\0') && (i + k) <= len)
		{
			if (little[k] == '\0')
				return ((char *)big + i);
			k++;
		}
		i++;
	}
	return (NULL);
}
