/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:44:59 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/13 20:07:09 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_rect(t_game *game, int pos_x, int pos_y, int len_x, int len_y, t_rgba color)
{
	//printf("drawing rect: start scr(x=%d, y=%d) - end scr(x=%d, y=%d)\n", pos_x, pos_y, pos_x + len_x, pos_y + len_y);
	
	for (int x = pos_x; x < pos_x + len_x; ++x) {
		for (int y = pos_y; y < pos_y + len_y; ++y) {
			mlx_put_pixel(game->img, x, y, rgba2color(color));
		}
	}
}

void	draw_map_tile(t_game *game, int map_x, int map_y)
{
	// game->scr_width
	// game->map_width
	int tile_width = game->scr_width / game->map_width;
	int tile_height = game->scr_height / game->map_height;
	
	int start_x = map_x * tile_width;
	int start_y = map_y * tile_height;

	int end_x = start_x + tile_width;
	int end_y = start_y + tile_height;

	for (int x = start_x; x < end_x; ++x) {
		for (int y = start_y; y < end_y; ++y) {
			if (game->map[map_y][map_x] == '0')
				mlx_put_pixel(game->img, x, y, rgba2color((t_rgba) {0, 0, 0, 255}));
			else if (game->map[map_y][map_x] == '1')
				mlx_put_pixel(game->img, x, y, rgba2color((t_rgba) {225, 255, 255, 255}));
		}
	}
}

void	draw2d(t_game *game)
{
	// Draw background
	draw_rect(game, 0, 0, game->scr_width, game->scr_height, (t_rgba) {255, 0, 255, 255});
	
	float scale_horizontal = game->scr_width  / game->map_width;
	float scale_vertical   = game->scr_height / game->map_height;
	
	int tile_width  = 1 * scale_horizontal;
	int tile_height = 1 * scale_vertical;

	// Draw map tiles
	for (int map_y = 0; map_y < game->map_height; ++map_y) {
		for (int map_x = 0; map_x < game->map_width; ++map_x) {
			int start_x = map_x * tile_width;
			int start_y = map_y * tile_height;
			
			t_rgba color;
			if (game->map[map_y][map_x] == '0') color = (t_rgba) {0, 0, 0, 255};
			else color = (t_rgba) {225, 225, 225, 255};
			
			// printf("printing map[y=%d][x=%d] ", map_x, map_y);
			draw_rect(game, start_x, start_y, tile_width - 1, tile_height - 1, color);
		}
	}

	// Draw player
	draw_rect(game, game->px * scale_horizontal, game->py * scale_vertical, 10, 10, (t_rgba) {255, 127, 0, 255});

	// Draw front point of player
	float player_front_dist = 1.0;
	float player_front_x = game->px + player_front_dist * sin(game->p_angle);
	float player_front_y = game->py + player_front_dist * cos(game->p_angle);
	draw_rect(game, player_front_x * scale_horizontal, player_front_y * scale_vertical, 5, 5, (t_rgba) {220, 50, 0, 255});
}
