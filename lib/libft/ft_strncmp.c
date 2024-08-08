/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:12:20 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/13 20:25:15 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Similar to strcmp(), except it compares first `cmp_lim` bytes at most. */
int	ft_strncmp(char *s1, char *s2, size_t cmp_lim)
{
	size_t			i;
	unsigned char	*u1;
	unsigned char	*u2;

	u1 = (unsigned char *) s1;
	u2 = (unsigned char *) s2;
	i = 0;
	while (i < cmp_lim)
	{
		if (u1[i] != u2[i])
			return (u1[i] - u2[i]);
		if (u1[i] == '\0')
			return (0);
		++i;
	}
	return (0);
}
