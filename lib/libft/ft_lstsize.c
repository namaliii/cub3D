/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:08:16 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/14 15:51:23 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Return the number of nodes present in the list. */
int	ft_lstsize(t_list *head)
{
	t_list	*iterator;
	int		counter;

	iterator = head;
	counter = 0;
	while (iterator != NULL)
	{
		iterator = iterator->next;
		++counter;
	}
	return (counter);
}
