/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:02:54 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/13 20:07:22 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
   Compare `cmp_lim` bytes of string `s1` and string `s2` as unsigned chars.
   Return -1 if `s1` < `s2`, 0 if they are identical, and 1 if `s1` > `s2`.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t cmp_lim)
{
	size_t			i;
	unsigned char	*ptr_uc_1;
	unsigned char	*ptr_uc_2;

	ptr_uc_1 = (unsigned char *) s1;
	ptr_uc_2 = (unsigned char *) s2;
	i = 0;
	while (i < cmp_lim)
	{
		if (*ptr_uc_1 != *ptr_uc_2)
			return (*ptr_uc_1 - *ptr_uc_2);
		++ptr_uc_1;
		++ptr_uc_2;
		++i;
	}
	return (0);
}
