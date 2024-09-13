/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:44:59 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/13 16:13:00 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TODO: You can put scale_horiz and scale_vert in the game struct as minimap variables
// TODO: You can create a minimap_line struct to pack length, thickness, color
static void	draw_line_from_player(t_game *game, float scale_horiz, float scale_vert, float angle_offset, float length, int thickness, t_rgba color)
{
	float	front_dist;
	float	front_x;
	float	front_y;

	front_dist = length;
	while (front_dist > 0)
	{
		front_x = game->px + front_dist * sin(game->p_angle_rad + angle_offset);
		front_y = game->py + front_dist * cos(game->p_angle_rad + angle_offset);
		if (front_x >= game->map_width || front_y >= game->map_height)
		{
			front_dist -= 0.05;
			continue ;
		}
		draw_safe_rect(game, front_x * scale_horiz - thickness / 2, front_y * scale_vert - thickness / 2, thickness, thickness, color);
		front_dist -= 0.05;
	}
}

static void	draw_map_tiles(t_game *game, int tile_width, int tile_height)
{
	t_rgba	tile_color;
	int		map_x;
	int		map_y;

	map_y = 0;
	while (map_y < game->map_height)
	{
		map_x = 0;
		while (map_x < game->map_width)
		{
			if (game->map[map_y][map_x] == DOOR_CLOSED_CHAR)
				tile_color = (t_rgba){20, 20, 175, 255};
			else if (game->map[map_y][map_x] == DOOR_OPENED_CHAR)
				tile_color = (t_rgba){20, 20, 100, 255};
			else if (is_wall(game, map_x, map_y))
				tile_color = (t_rgba){175, 175, 175, 255};
			else
				tile_color = (t_rgba){0, 0, 0, 255};
			draw_safe_rect(game, map_x * tile_width, map_y * tile_height, \
tile_width - 1, tile_height - 1, tile_color);
			++map_x;
		}
		++map_y;
	}
}

void	draw_minimap(t_game *game)
{
	float	scale_horizontal;
	float	scale_vertical;

	scale_horizontal = (game->scr_width / 3) / game->map_width;
	scale_vertical = (game->scr_height / 3) / game->map_height;
	draw_safe_rect(game, 0, 0, scale_horizontal * game->map_width, scale_vertical * game->map_height, (t_rgba){50, 50, 50, 255});
	draw_map_tiles(game, 1 * scale_horizontal, 1 * scale_vertical);
	if (game->px < game->map_width && game->py < game->map_height)
		draw_safe_rect(game, game->px * scale_horizontal - 4, game->py * scale_vertical - 4, 10, 10, (t_rgba){255, 127, 0, 255});
	draw_line_from_player(game, scale_horizontal, scale_vertical, 0, 1, 2, (t_rgba){225, 50, 50, 255});
	draw_line_from_player(game, scale_horizontal, scale_vertical, -game->fov_rad / 2, 6, 1, (t_rgba){50, 50, 125, 255});
	draw_line_from_player(game, scale_horizontal, scale_vertical, +game->fov_rad / 2, 6, 1, (t_rgba){50, 50, 125, 255});
}
