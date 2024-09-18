/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:44:59 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/16 23:55:32 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_line_from_player(\
t_game *game, float angle_offset, t_minimap *mmap)
{
	float	front_dist;
	float	front_x;
	float	front_y;

	front_dist = mmap->line_len;
	while (front_dist > 0)
	{
		front_x = game->px + front_dist * sin(game->p_angle_rad + angle_offset);
		front_y = game->py + front_dist * cos(game->p_angle_rad + angle_offset);
		if (front_x >= game->map_width || front_y >= game->map_height)
		{
			front_dist -= 0.05;
			continue ;
		}
		draw_safe_rect(game, front_x * mmap->scale_horiz - mmap->line_thick / 2, front_y * mmap->scale_vert - mmap->line_thick / 2, mmap->line_thick, mmap->line_thick, mmap->line_color);
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

static void	draw_background(t_game *game, float scale_horizontal, float scale_vertical)
{
	draw_safe_rect(game, 0, 0, scale_horizontal * game->map_width, scale_vertical * game->map_height, (t_rgba){50, 50, 50, 255});
}

static void	draw_player(t_game *game, float scale_horizontal, float scale_vertical)
{
	draw_safe_rect(game, game->px * scale_horizontal - 4, game->py * scale_vertical - 4, 10, 10, (t_rgba){255, 127, 0, 255});
}

void	draw_minimap(t_game *game)
{
	t_minimap	mmap;

	mmap.scale_horiz = (game->scr_width / 3.0) / game->map_width;
	mmap.scale_vert = (game->scr_height / 3.0) / game->map_height;
	draw_background(game, mmap.scale_horiz, mmap.scale_vert);
	draw_map_tiles(game, 1.0 * mmap.scale_horiz, 1.0 * mmap.scale_vert);
	if (game->px < game->map_width && game->py < game->map_height)
		draw_player(game, mmap.scale_horiz, mmap.scale_vert);
	mmap.line_len = 1;
	mmap.line_thick = 2;
	mmap.line_color = (t_rgba){225, 50, 50, 255};
	draw_line_from_player(game, 0, &mmap);
	mmap.line_len = 6;
	mmap.line_thick = 1;
	mmap.line_color = (t_rgba){50, 50, 125, 255};
	draw_line_from_player(game, -game->fov_rad / 2, &mmap);
	draw_line_from_player(game, +game->fov_rad / 2, &mmap);
}
