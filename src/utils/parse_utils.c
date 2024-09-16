/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:24:11 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/16 18:19:05 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_realloc(void *ptr, size_t original_size, size_t new_size)
{
	void	*new_ptr;
	size_t	min_size;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (!ptr)
		return (new_ptr);
	min_size = original_size;
	if (new_size < original_size)
		min_size = new_size;
	if (min_size > 0)
		ft_memcpy(new_ptr, ptr, min_size);
	free(ptr);
	return (new_ptr);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' && str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	is_valid_extension(char *file_name)
{
	int		length;

	length = ft_strlen(file_name);
	if (length < 4)
	{
		printf("%s\n", ERR_MSG_MAP_EXT_INVALID);
		return (0);
	}
	if (file_name[length - 4] != '.'
		|| file_name[length - 3] != 'c'
		|| file_name[length - 2] != 'u'
		|| file_name[length - 1] != 'b')
	{
		printf("%s\n", ERR_MSG_MAP_EXT_INVALID);
		return (0);
	}
	return (1);
}
