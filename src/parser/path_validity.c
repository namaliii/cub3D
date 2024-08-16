/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:30:16 by anamieta          #+#    #+#             */
/*   Updated: 2024/08/16 19:37:08 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**copy_map(char **original, int height)
{
	char	**copy;
	int		len;
	int		i;

	copy = (char **)safe_calloc(height + 1, sizeof(char *));
	i = 0;
	while (i < height)
	{
		len = ft_strlen(original[i]);
		copy[i] = (char *)ft_calloc(len + 1, sizeof(char));
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		ft_strlcpy(copy[i], original[i], len + 1);
		i++;
	}
	return (copy);
}

void	fill(char **array, int width, int height, int x, int y)
{
	if (x < 0 || y < 0 || y >= height || x >= (int)ft_strlen(array[y])
		|| array[y][x] == 'Q' || ft_isspace(array[y][x]))
		return ;
	array[y][x] = 'Q';
	fill(array, width, height, x + 1, y);
	fill(array, width, height, x - 1, y);
	fill(array, width, height, x, y + 1);
	fill(array, width, height, x, y - 1);
}

void	flood_fill(char **array, int height)
{
	int	width;
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		if (array[y] != NULL)
		{
			width = ft_strlen(array[y]);
			x = 0;
			while (x < width)
			{
				if (!ft_isspace(array[y][x]) && array[y][x] != 'Q')
					fill(array, width, height, x, y);
				x++;
			}
		}
		y++;
	}
}

void	valid_path(t_game *game)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = copy_map(game->map, game->map_height);
	if (!map_copy)
	{
		printf("Failed to copy map.\n");
		return ;
	}
	flood_fill(map_copy, game->map_height);
	// just printing
	printf("Map after floodfill:\n");
	i = 0;
	while (i < game->map_height)
	{
		if (map_copy != NULL)
		{
			printf("i %d: %s\n", i, map_copy[i]);
		}
		else
			printf("Line %d is NULL\n", i);
		i++;
	}
	i = 0;
	while (i < game->map_height)
	{
		if (map_copy != NULL)
		{
			j = 0;
			int width = ft_strlen(map_copy[i]) - 1;
			while (j < width)
			{
				if (map_copy[i][j] != 'Q' && !ft_isspace(map_copy[i][j]))
					error_handling(game, game->map, "Map has to be one piece");
				j++;
			}
		}
		i++;
	}
	free_2d_array(map_copy, game->map_height);
}
