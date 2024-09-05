/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:30:16 by anamieta          #+#    #+#             */
/*   Updated: 2024/08/27 17:45:52 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**copy_map(char **original, int height, int width)
{
	char	**copy;
	int		i;

	copy = (char **)safe_calloc(height + 1, sizeof(char *));
	i = 0;
	while (i < height)
	{
		copy[i] = (char *)ft_calloc(width + 1, sizeof(char));
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		ft_strlcpy(copy[i], original[i], width + 1);
		i++;
	}
	return (copy);
}

void	fill(char **array, int height, int width, int x, int y)
{
	if (x < 0 || y < 0 || y >= height || x >= width
		|| array[y][x] == 'Q' || ft_isspace(array[y][x]))
		return ;

	array[y][x] = 'Q';
	fill(array, height, width, x + 1, y);
	fill(array, height, width, x - 1, y);
	fill(array, height, width, x, y + 1);
	fill(array, height, width, x, y - 1);
}

void	flood_fill(char **map_copy, int height, int width)
{
	int		i;
	int		j;

	i = 0;
	while (i < height && map_copy[i])
	{
		j = 0;
		while (ft_isspace(map_copy[i][j]) && j < width)
			j++;
		if (!ft_isspace(map_copy[i][j]))
			break ;
		i++;
	}
	fill(map_copy, height, width, j, i);
}

void	check_the_path(t_game *game, char **map_copy, int height)
{
	int	i;
	int	j;

	i = 0;
	(void)height;
	while (i < game->map_height)
	{
		if (map_copy[i] != NULL)
		{
			j = 0;
			while (j < game->map_width)
			{
				if (map_copy[i][j] != 'Q' && !ft_isspace(map_copy[i][j]))
					exit_error_parser(game, game->map, "Map has to be one piece");
				j++;
			}
		}
		i++;
	}
}

void	valid_path(t_game *game)
{
	char	**map_copy;

	map_copy = copy_map(game->map, game->map_height, game->map_width);
	if (!map_copy)
	{
		printf("Failed to copy map for path validity check.\n");
		return ;
	}
	flood_fill(map_copy, game->map_height, game->map_width);
	check_the_path(game, map_copy, game->map_height);
	free_2d_array(map_copy, game->map_height);
}
