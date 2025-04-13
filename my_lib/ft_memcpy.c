/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:17:07 by natrodri          #+#    #+#             */
/*   Updated: 2024/10/08 11:49:45 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

/*#include <stdio.h>
#include <string.h>
int	main()
{
	int	test[4] = {0, 1, 2, 3};
	int	test2[4];
	int	t3[4] = {0, 1, 2, 3};
	int	t4[4];
	int	*resul;
	int	*resul2;
		
	resul = (int *)ft_memcpy(test2, test, 16);
	resul2 = (int *)memcpy(t4, t3, 16);
	for (size_t i = 0; i < 4; i++)
	{
		printf("%d", resul[i]);
		//printf("%d", resul2[i]);
	}
}*/
