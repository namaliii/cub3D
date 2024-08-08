/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:24:30 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/13 16:49:45 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Prevent underflow! */
#define SIZE_T_MIN 0

/* 
   Search the last occurrance of char `c` in string `s` and return a pointer 
   to it. 

   Include the '\0' character to the comparison. If `c` is '\0', 
   function should locate the terminating '\0'.
   
   Return NULL if `c` is not found.
*/
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (1)
	{
		if (s[i] == (char) c)
		{
			return ((char *)(s + i));
		}
		if (i == SIZE_T_MIN)
			break ;
		--i;
	}
	return (NULL);
}
