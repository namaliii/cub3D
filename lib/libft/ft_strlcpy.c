/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:38:38 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/22 13:54:21 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Prevent underflow! */
#define SIZE_T_MIN 0

/*
  Both `src` and `dest` should be null-terminated strings.

  * Copies upto `dstsize` - 1 characters or until end of `src` 
  from `src` to `dest`, then null-terminates the result.

  Returns how many characters are in `src` initially. (Length, excludes '\0')
  
  * If `dstsize` is 0, it can't null-terminate, just returns `src` length.

  Unlike strncpy(),
    * This accepts full size of the buffer as `dstsize`, including '\0'. 
	Not just length (excluding '\0') of the array to be copied.
	* Null-terminates `dest`, but does not pad its ending with '\0' 
	like strncpy().
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && dstsize != SIZE_T_MIN && i < (dstsize - 1))
	{
		dest[i] = src[i];
		++i;
	}
	if (dstsize > 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}
