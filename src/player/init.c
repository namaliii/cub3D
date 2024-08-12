/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:04:17 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/12 17:17:47 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_vec2d	player_get_spawn_coords(t_map *map)
{
	return ((t_vec2d) {0.0, 0.0});
}

static float	player_get_spawn_angle(t_map *map)
{
	return (0.0);
}

void	init_player(t_player *player, t_map *map)
{
	int first_free_x, first_free_y;

	for (first_free_y = 0; first_free_y < MOCK_MAP_WIDTH; ++first_free_y) {
		for (first_free_x = 0; first_free_x < MOCK_MAP_HEIGHT; ++first_free_x) {
			if (map->map[first_free_y, first_free_x] == '0')
				goto found;	
		}
	}

found:
	player->posx = first_free_x;
	player->posy = first_free_y;
	player->angle = 0.0;
}
