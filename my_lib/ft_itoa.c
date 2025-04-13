/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:58:11 by natrodri          #+#    #+#             */
/*   Updated: 2024/10/08 11:46:36 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*isnegative(char *str, int n, int c)
{
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			str[c - 1] = '8';
			n = 214748364;
			c--;
		}
		else
			n *= -1;
	}
	while (--c > 0)
	{
		str[c] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		c;
	char	*str;
	int		nb;

	nb = n;
	c = count(n);
	str = (char *)malloc((c + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[c] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
		return (isnegative(str, nb, c));
	while (--c >= 0)
	{
		str[c] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
/*#include <stdio.h>
int	main()
{
	printf("%s", ft_itoa(-1212121));
}*/
