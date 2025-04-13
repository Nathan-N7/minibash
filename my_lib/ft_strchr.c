/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:06:28 by natrodri          #+#    #+#             */
/*   Updated: 2024/10/08 11:00:31 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char *)s;
	if (c > 255)
		return (s2);
	while (s2[i] != '\0')
	{
		if (s2[i] == c)
			return (&s2[i]);
		i++;
	}
	if (s2[i] == (char)c)
		return ((char *)&s2[i]);
	return (0);
}
