/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:09:39 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/12 15:19:19 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Write character `c` into file descriptor `fd`. */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
