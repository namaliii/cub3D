/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:02:14 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/31 00:41:52 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
   Copy `len` bytes from string `src` to string `dest`.
   If dest > src, start copying from end to beginning for avoiding data loss.
   Return `dest`.
   Return NULL if `dest` and `src` is NULL.
*/
void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t		i;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest > src)
	{
		i = len;
		while (i-- > 0)
		{
			*((char *) dest + i) = *((const char *) src + i);
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*((char *) dest + i) = *((const char *) src + i);
			++i;
		}
	}
	return (dest);
}
