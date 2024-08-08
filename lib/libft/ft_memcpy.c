/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:02:11 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/12 16:00:19 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
   Copy `n` bytes from `src` to `dest`.

   Undefined behaviour if `src` and `dest` overlap.
   Appliactions in which `dest` and `src` might overlap should use memmove().

   Returns the original value of `dest`.
*/
void	*ft_memcpy(void	*dest, const void	*src,	size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*((unsigned char *) dest + i) = *((unsigned char *) src + i);
		++i;
	}
	return (dest);
}
