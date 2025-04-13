/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:25:38 by natrodri          #+#    #+#             */
/*   Updated: 2024/10/08 11:59:24 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = -1;
	if (!s || !f)
		return ;
	while (s[++i] != '\0')
		f(i, &s[i]);
}

/*void	test(unsigned int i, char *s)
{
	*s = i + *s;
}

#include <stdio.h>

int	main()
{
	char	s[] = "test";
	ft_striteri(s, test);
	printf("%s", s);
}*/
