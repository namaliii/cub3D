/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:06:17 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/14 15:45:31 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
   Delete the whole list starting from where `head` points.
   Use `del_content` function in order to delete the contents of the nodes.
   Point `head` to NULL when done.
*/
void	ft_lstclear(t_list **head, void (*del_content)(void *))
{
	t_list	*list;
	t_list	*prev;

	if (*head == NULL)
		return ;
	list = *head;
	while (list->next != NULL)
	{
		prev = list;
		list = list->next;
		del_content(prev->content);
		free(prev);
	}
	del_content(list->content);
	free(list);
	*head = NULL;
}
