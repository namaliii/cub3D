/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:24:11 by anamieta          #+#    #+#             */
/*   Updated: 2024/08/27 18:25:04 by anamieta         ###   ########.fr       */
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

int	valid_extension(char *file_name)
{
	int		length;

	length = ft_strlen(file_name) - 1;
	if (file_name[length - 3] != '.' || file_name[length - 2] != 'c'
		|| file_name[length - 1] != 'u' || file_name[length] != 'b')
	{
		printf("%s", "Map extension invalid");
		return (1);
	}
	return (0);
}