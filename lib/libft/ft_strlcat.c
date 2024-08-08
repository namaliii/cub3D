/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:27:52 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/20 15:44:28 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
   Append at most `dstsize - strlen(dest) - 1` bytes from `src` to `dest`.
   Null-terminate the result.

   Return the total length of the string that was tried to be created.
     *  If operation is successful, it will be stlren(dest) + strlen(src).
	 *  If dstsize > 0 or strlen(dest) is already > dstsize,
	      return dstsize + strlen(src) because it was attempted to create
		  a string that has this length.
*/
size_t	ft_strlcat(char *dest, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;
	size_t	dest_available_space;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (dstsize == 0 || dstsize <= dest_len)
		return (dstsize + src_len);
	i = 0;
	j = dest_len;
	dest_available_space = dstsize - dest_len - 1;
	while (src[i] != '\0' && i < dest_available_space)
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (dest_len + src_len);
}
