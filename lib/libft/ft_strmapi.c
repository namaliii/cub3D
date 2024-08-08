/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:23:24 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/14 17:48:57 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
   Return a duplicate string of `s` where each character was processed through
   function `f`.
   Return NULL if memory allocation fails.
   Function `f` takes index and value of the character as arguments.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapped_str;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	mapped_str = (char *) malloc((s_len + 1) * sizeof(char));
	if (mapped_str == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		mapped_str[i] = f(i, s[i]);
		++i;
	}
	mapped_str[s_len] = '\0';
	return (mapped_str);
}
