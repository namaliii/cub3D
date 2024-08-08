/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:01:14 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/12 15:17:23 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*s_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

/* Return a duplicate of the string `src`. */
char	*ft_strdup(char *src)
{
	char	*dup;
	size_t	siz;

	siz = ft_strlen(src) + 1;
	dup = (char *) malloc(siz * sizeof(char));
	if (!dup)
		return (0);
	return (s_strncpy(dup, src, siz));
}
