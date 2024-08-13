/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:04:17 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/13 14:54:02 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static t_vec2d	player_get_spawn_coords(t_map *map)
// {
// 	return ((t_vec2d) {0.0, 0.0});
// }

// static float	player_get_spawn_angle(t_map *map)
// {
// 	return (0.0);
// }

void	init_player(t_player *player, t_map *map)
{
	int first_free_x, first_free_y;
	int found_flag = false;

	for (first_free_y = 0; first_free_y < map->height; ++first_free_y)
	{
		for (first_free_x = 0; first_free_x < map->width; ++first_free_x)
		{
			if (map->map[first_free_y][first_free_x] == '0')
			{
				player->posx = first_free_x + 0.5;
				player->posy = first_free_y + 0.5;
				found_flag = true;
				break;
			}
		}

		if (found_flag)
			break;
	}

	if (!found_flag)
		exit_error("Couldn't find a valid player spawn position.");

	player->angle = 0.0;
	player->game_over = false;
}
