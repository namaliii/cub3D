/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:59:30 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/14 18:30:42 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*joined_str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined_str = (char *) malloc((len1 + len2 + 1) * sizeof(char));
	if (joined_str == NULL)
		return (NULL);
	joined_str[0] = '\0';
	ft_strlcat(joined_str, (char *) s1, len1 + len2 + 1);
	ft_strlcat(joined_str, (char *) s2, len1 + len2 + 1);
	return (joined_str);
}
