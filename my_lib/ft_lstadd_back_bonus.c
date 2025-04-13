/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:39:15 by natrodri          #+#    #+#             */
/*   Updated: 2024/10/10 12:45:54 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!*lst)
	{
		(*lst) = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

/*#include <stdio.h>

void	*d(void *c)
{
	free(c);
	return (c);
}

int	main()
{
	t_list	*list1 = NULL;
	void	*c;

	t_list	*node1 = ft_lstnew("one");
	t_list  *node2 = ft_lstnew("two");
	t_list  *node3 = ft_lstnew("three");
	t_list  *node4 = ft_lstnew("four");
	printf("content N1: %s\n", (char *)node1->content);
	printf("content N2: %s\n", (char *)node2->content);
	printf("content N3: %s\n", (char *)node3->content);
	printf("content N4: %s\n\n", (char *)node4->content);

	ft_lstadd_front(&list1, node2);
	ft_lstadd_front(&list1, node1);
	ft_lstadd_back(&list1, node3);
	ft_lstadd_back(&list1, node4);

	printf("%p\n", node2);
	printf("%p\n\n", node1->next);

	printf("size: %d\n", ft_lstsize(list1));
	printf("last next node: %s", (char *)ft_lstlast(list1));

	c = node1->content;
	ft_lstdelone(node1, d(c));
	printf("valor de N1 deletado: %s\n", (char *)node1->content);
}*/
