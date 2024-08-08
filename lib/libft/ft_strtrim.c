/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:54:28 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/19 15:46:04 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Check whether `str` contains the character `ch` or not. */
static int	str_contains(char *str, char ch)
{
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen(str);
	i = 0;
	while (i < str_len)
	{
		if (str[i] == ch)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char *set)
{
	size_t	start_i;
	size_t	end_i;

	start_i = 0;
	while (str_contains(set, s[start_i]))
		++start_i;
	end_i = ft_strlen(s) - 1;
	while (str_contains(set, s[end_i]))
		--end_i;
	return (ft_substr(s, start_i, end_i - start_i + 1));
}
