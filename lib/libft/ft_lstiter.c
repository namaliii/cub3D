/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:06:56 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/14 15:50:37 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Iterate over list and send content of each note to function `f`.  */
void	ft_lstiter(t_list *head, void (*f)(void *))
{
	t_list	*iterator;

	iterator = head;
	while (iterator != NULL)
	{
		f(iterator->content);
		iterator = iterator->next;
	}
}
