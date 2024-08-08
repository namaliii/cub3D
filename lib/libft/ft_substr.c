/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:54:19 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/19 15:46:20 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_empty_string(void)
{
	return ((char *) ft_calloc(1, sizeof(char)));
}

static size_t	getmin(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

/* 
   Create and return a substring from `sub_start_idx` index of string `str` 
   with the length `sub_len`.
   Return an empty string if `sub_start_idx` >= length of `str`.
*/
char	*ft_substr(char const *str, unsigned int sub_start_idx, size_t sub_len)
{
	char	*sub;
	size_t	str_len;
	size_t	max_available_len;
	size_t	alloc_len;

	str_len = ft_strlen(str);
	if (sub_start_idx >= str_len || sub_len <= 0)
	{
		sub = create_empty_string();
		return (sub);
	}
	max_available_len = str_len - sub_start_idx;
	if (sub_len == SIZE_MAX)
		sub_len -= 1;
	alloc_len = getmin(sub_len, max_available_len) + 1;
	sub = (char *) malloc(alloc_len * sizeof(char));
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, ((char *) str + sub_start_idx), sub_len + 1);
	return (sub);
}
