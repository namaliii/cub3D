/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:24:11 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/17 00:05:05 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}
