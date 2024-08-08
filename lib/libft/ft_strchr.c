/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:01:11 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/18 20:08:18 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
