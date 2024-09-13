/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_numeric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:32:33 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/13 11:50:18 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	char_is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

/* Return whether string only consists of digits or not. It may have a sign*/
int	str_is_numeric(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!char_is_numeric(s[i]))
			return (0);
		++i;
	}
	return (1);
}
