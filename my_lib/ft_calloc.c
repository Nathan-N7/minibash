/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:56:49 by natrodri          #+#    #+#             */
/*   Updated: 2024/10/08 11:50:38 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*ptr;

	if (nmeb != 0 && (nmeb * size) / nmeb != size)
		return (NULL);
	ptr = malloc(nmeb * size);
	if (!ptr)
		return (NULL);
	ft_memset((unsigned char *)ptr, '\0', nmeb * size);
	return (ptr);
}

/*#include <stdio.h>
#include <limits.h>
int	main()
{
	//int	a = SIZE_MAX;
	int	d = ft_calloc(-5, -5) == NULL;

	printf("%d", d);
}*/
