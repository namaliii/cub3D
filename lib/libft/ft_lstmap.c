/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:07:38 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/20 15:30:15 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Free all elements in the list. Delete contents using `del_content` func. */
void	free_all(t_list *head, void (*del_content)(void *))
{
	t_list	*iterator;
	t_list	*curr_node_to_free;

	iterator = head;
	while (iterator != NULL)
	{
		del_content(iterator->content);
		curr_node_to_free = iterator;
		iterator = iterator->next;
		free(curr_node_to_free);
	}
}

/*
   Iterates `list` and creates another list containing a copy of each node.
   Contents of each node is copied to the new list using the function `f`.
   
   If any allocation fails while creating the new list, 
   contents are deleted using `del_content` function while freeing new nodes.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del_content)(void *))
{
	t_list	*iterator;
	t_list	*new_head;
	t_list	*new_iterator;

	if (f == NULL || del_content == NULL)
		return (NULL);
	new_head = NULL;
	iterator = lst;
	while (iterator != NULL)
	{
		new_iterator = ft_lstnew(f(iterator->content));
		if (new_iterator == NULL)
		{
			free_all(new_head, del_content);
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&new_head, new_iterator);
		iterator = iterator->next;
	}
	return (new_head);
}
