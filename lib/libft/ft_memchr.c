/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:18:51 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/13 16:21:16 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
  Search first `search_lim` bytes of `ptr`.
  Find the first occurrance of `value` interpreted as an `unsigned char`.
  Return a pointer to it.
*/
void	*ft_memchr(const void *ptr, int value, size_t search_lim)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *) ptr;
	i = 0;
	while (i < search_lim)
	{
		if (p[i] == (unsigned char) value)
			return (&p[i]);
		++i;
	}
	return (NULL);
}
