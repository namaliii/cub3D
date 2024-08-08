/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:04:17 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/18 14:30:45 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Count how many digits are in integer `nb`. */
static int	count_digits(int nb)
{
	int	digit_count;

	if (nb == 0)
		return (1);
	digit_count = 0;
	while (nb != 0)
	{
		nb /= 10;
		++digit_count;
	}
	return (digit_count);
}

/* 
   Allocate just enough memory to store the resultant string and return it.
   Returns NULL if malloc fails.
*/
static char	*alloc_memory(int nb)
{
	char	*mem;
	int		alloc_size;

	alloc_size = count_digits(nb) + 1;
	if (nb < 0)
		alloc_size += 1;
	mem = (char *) malloc(alloc_size * sizeof(char));
	if (mem == NULL)
		return (NULL);
	return (mem);
}

/* 
   Parse integer `nb` into string and return it.
   Return NULL if allocation fails.
*/
char	*ft_itoa(int nb)
{
	char	*buff;
	int		buff_idx;

	buff = alloc_memory(nb);
	if (buff == NULL)
		return (NULL);
	if (nb >= 0)
	{
		buff_idx = count_digits(nb);
		buff[0] = '0';
		nb = -nb;
	}
	else
	{
		buff_idx = count_digits(nb) + 1;
		buff[0] = '-';
	}
	buff[buff_idx--] = '\0';
	while (nb < 0)
	{
		buff[buff_idx--] = '0' + -(nb % 10);
		nb /= 10;
	}
	return (buff);
}
