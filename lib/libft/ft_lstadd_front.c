/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:05:49 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/14 16:07:26 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
   Add `new` node at the beginning of the list pointed by `head`.
   `new` will be the new head of the list.
*/
void	ft_lstadd_front(t_list **head, t_list *new_node)
{
	if (*head == NULL)
		*head = new_node;
	else
	{
		new_node->next = *head;
		*head = new_node;
	}
}
