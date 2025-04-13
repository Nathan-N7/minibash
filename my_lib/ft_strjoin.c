/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:33:20 by natrodri          #+#    #+#             */
/*   Updated: 2024/10/01 13:25:20 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		c1;
	int		c2;
	int		i;
	char	*str;

	c1 = ft_strlen(s1);
	c2 = ft_strlen(s2);
	str = (char *)malloc((c1 + c2 + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	i = -1;
	while (s2[++i])
		str[c1++] = s2[i];
	str[c1] = '\0';
	return (str);
}

/*#include <stdio.h>
int	main()
{
	printf("%s", ft_strjoin("vamos ", "testar"));
}*/
