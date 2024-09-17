/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:30:16 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/17 01:03:14 by tunsal           ###   ########.fr       */
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

void	fill(char **array, int height_width[2], int x, int y)
{
	if (x < 0 || y < 0 || y >= height_width[0] || x >= height_width[1]
		|| array[y][x] == 'Q' || ft_isspace(array[y][x]))
		return ;
	array[y][x] = 'Q';
	fill(array, height_width, x + 1, y);
	fill(array, height_width, x - 1, y);
	fill(array, height_width, x, y + 1);
	fill(array, height_width, x, y - 1);
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
	fill(map_copy, (int []){height, width}, j, i);
}

void	check_the_path(t_game *g, char **map_copy, int height)
{
	int	i;
	int	j;

	i = 0;
	(void)height;
	while (i < g->map_height)
	{
		if (map_copy[i] != NULL)
		{
			j = 0;
			while (j < g->map_width)
			{
				if (map_copy[i][j] != 'Q' && !ft_isspace(map_copy[i][j]))
					exit_error_parser(g, g->map, ERR_MSG_MAP_NOT_ONE_PIECE);
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
		printf("%s\n", ERR_MSG_MAP_VAL_CHCK_COPY_FAIL);
		return ;
	}
	flood_fill(map_copy, game->map_height, game->map_width);
	check_the_path(game, map_copy, game->map_height);
	free_2d_array(map_copy, game->map_height);
}
