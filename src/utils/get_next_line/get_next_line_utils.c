/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:09:29 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/07 21:38:18 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

char	*ft_substr(char const *src, unsigned int index, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	n;

	if (src == NULL)
		return (NULL);
	if (len > ft_strlen(src))
		len = ft_strlen(&src[index]);
	i = 0;
	n = ft_strlen(src);
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (src[index] && len-- && index <= n)
		dest[i++] = src[index++];
	dest[i] = '\0';
	return (dest);
}

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

/* 
   Search the first occurrance of char `c` in string `s` and return a pointer 
   to it. Return NULL if `c` is not found.
*/
char	*ft_strchr(const char *s, int c)
{
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len + 1)
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		++i;
	}
	return (NULL);
}
