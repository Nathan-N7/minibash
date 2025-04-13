/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:36:39 by natrodri          #+#    #+#             */
/*   Updated: 2024/10/08 11:48:51 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *str, char charset)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] != charset && str[i] != '\0')
		{
			c++;
			while (str[i] != charset && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (c);
}

static char	*substring(char const *str, int start, int length)
{
	char	*substr;
	int		j;

	substr = malloc((length + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	j = -1;
	while (++j < length)
		substr[j] = str[start + j];
	substr[length] = '\0';
	return (substr);
}

static char	**alok_a(char const *str, char c)
{
	char	**array;

	array = malloc((count(str, c) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	else
		return (array);
}

static	char	**verify_alok(char **array, int k)
{
	int	j;

	j = 0;
	while (j < k)
	{
		free(array[j]);
		j++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		k;
	int		start;
	char	**array;

	i = 0;
	k = 0;
	array = alok_a(str, c);
	while (str[i] != '\0')
	{
		if (str[i] != c && str[i])
		{
			start = i;
			while (str[i] != c && str[i] != '\0')
				i++;
			array[k] = substring (str, start, i - start);
			if (array[k] == NULL)
				return (verify_alok(array, k));
			k++;
		}
		else
			i++;
	}
	array[k] = NULL;
	return (array);
}

/*#include <stdio.h>
int	main()
{
	char **array = ft_split("chinimala", ' ');
	printf("%s", array[1]);
}*/
