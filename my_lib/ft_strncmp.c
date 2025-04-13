/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:00:46 by natrodri          #+#    #+#             */
/*   Updated: 2024/10/10 12:31:53 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s;

	s = (unsigned char *)s1;
	i = 0;
	if (n == 0)
		return (0);
	while (s[i] && s2[i] && s[i] == s2[i] && i < (n - 1))
	{
		i++;
	}
	return (s[i] - s2[i]);
}

/*#include <stdio.h>
int   main(void)
{
        const char a[] = "abataxi";
        const char b[] = "abacaxi";
        int p;

        p = ft_strncmp(a, b, 4);
        printf("%d", p);
}*/
