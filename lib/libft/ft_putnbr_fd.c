/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:16:51 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/13 16:45:57 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
   Longest integer we can receive is -2147483647 with length 11.
   We need 12 characters including the null-terminator.
*/
#define BUFF_SIZE 12

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

/* Write integer `n` into the file descriptor `fd`. */
void	ft_putnbr_fd(int nb, int fd)
{
	char	buff[BUFF_SIZE];
	int		buff_idx;

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
	write(fd, buff, ft_strlen(buff));
}
