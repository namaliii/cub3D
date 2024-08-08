/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:22:00 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/11 15:05:31 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
   Writes `replace_lim` bytes of value `val` (converted to an unsigned char)
   to the string `str`.
*/
void	*ft_memset(void *str, int val, size_t replace_lim)
{
	size_t	i;

	i = 0;
	while (i < replace_lim)
	{
		*((unsigned char *) str + i) = (unsigned char) val;
		++i;
	}
	return (str);
}
