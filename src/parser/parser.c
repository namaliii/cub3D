/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:25 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/12 15:35:06 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_mock_map(t_map *map)
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
}

t_map	*parse(int argc, char *argv[])
{
	t_map	*map;

	(void)argc;
	(void)argv;
	map = (t_map *) safe_calloc(1, sizeof(map));
	create_mock_map(map);
	return (map);
}
