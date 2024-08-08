/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:24:10 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/18 15:52:57 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Write `n` bytes of 0 into the memory starting from `s`. */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
