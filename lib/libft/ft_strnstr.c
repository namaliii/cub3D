/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:23:59 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/14 13:20:26 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
   Locate the first occurrance of null-terminated string `needle` in the
   null-terminated string `needle`. Return a pointer to the first character
   of the occurrance.

   If `needle` is an empty string, return `haystack`.
   If `needle` is not found, return NULL.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t searchlim)
{
	size_t	i;
	size_t	j;
	size_t	haystack_len;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *) haystack);
	haystack_len = ft_strlen(haystack);
	if (needle_len > haystack_len)
		return (NULL);
	i = 0;
	while (i < haystack_len && i < searchlim)
	{
		j = 0;
		while (haystack[i + j] != '\0' && needle[j] != '\0'
			&& i + j < searchlim && haystack[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
