/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:05:17 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/14 16:08:49 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Add `new` node at the end of the list pointed by `head`. */
void	ft_lstadd_back(t_list **head, t_list *new)
{
	t_list	*last;

	if (*head == NULL)
		*head = new;
	else
	{
		last = ft_lstlast(*head);
		last->next = new;
	}
}
