/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:10:50 by natrodri          #+#    #+#             */
/*   Updated: 2024/10/12 14:44:30 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*check;
	t_list	*save;

	check = *lst;
	while (check != NULL)
	{
		save = check->next;
		del(check->content);
		free(check);
		check = save;
	}
	*lst = NULL;
}
