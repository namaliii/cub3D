/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:25 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/12 16:03:53 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_mock_map(t_map *map)
{
	int	i;

	map->height = MOCK_MAP_HEIGHT;
	map->map = (char **) safe_calloc(map->height, sizeof(char *));	
	map->width = MOCK_MAP_WIDTH;
	i = 0;
	while (i < MOCK_MAP_HEIGHT)
	{
		map->map[i] = (char *) safe_calloc(map->width, sizeof(char));
		++i;
	}
	map->color_floor = (t_color) {255, 127, 0, 255};
	map->color_ceiling = (t_color) {50, 10, 10, 255};
	map->tex_NO_path = NULL;
	map->tex_SO_path = NULL;
	map->tex_WE_path = NULL;
	map->tex_EA_path = NULL;
	
	char m1[MOCK_MAP_HEIGHT][MOCK_MAP_WIDTH] = {
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '1', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '1', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '1', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
	};
	
	for (int y = 0; y < MOCK_MAP_HEIGHT; ++y) {
		for (int x = 0; x < MOCK_MAP_WIDTH; ++x) {
			map->map[y][x] = m1[y][x];
		}
	}
}

void	init_map(t_map *map)
{
	map->height = -1;
	map->width = -1;
	map->map = NULL;
	map->color_floor = (t_color) {255, 127, 0, 255};
	map->color_ceiling = (t_color) {50, 10, 10, 255};
	map->tex_NO_path = NULL;
	map->tex_SO_path = NULL;
	map->tex_WE_path = NULL;
	map->tex_EA_path = NULL;
}

t_map	*parse(int argc, char *argv[])
{
	t_map	*map;

	(void)argc;
	(void)argv;
	map = (t_map *) safe_calloc(1, sizeof(map));
	init_map(map);
	set_mock_map(map);
	return (map);
}
