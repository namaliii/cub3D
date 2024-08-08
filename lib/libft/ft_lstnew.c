/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:08:01 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/19 17:01:43 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
   Create a new list node and return a pointer to it. 
   Return NULL if malloc fails.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *) malloc(1 * sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
