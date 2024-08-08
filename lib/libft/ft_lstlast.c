/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:07:15 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/14 15:53:45 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Get the last node that is linked to `head`. */
t_list	*ft_lstlast(t_list *head)
{
	t_list	*last;

	if (head == NULL)
		return (0);
	last = head;
	while (last->next != NULL)
		last = last->next;
	return (last);
}
