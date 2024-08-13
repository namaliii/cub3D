/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:44:59 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/13 22:37:23 by tunsal           ###   ########.fr       */
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

static void	draw_line_from_player(t_game *game, float scale_horiz, float scale_vert, float angle_offset)
{
	for (float front_dist = 1; front_dist > 0; front_dist -= .05) {
		float front_x = game->px + front_dist * sin(game->p_angle + angle_offset);
		float front_y = game->py + front_dist * cos(game->p_angle + angle_offset);
		draw_rect(game, front_x * scale_horiz, front_y * scale_vert, 2, 2, (t_rgba) {220, 50, 0, 255});
	}
}

void	draw_minimap(t_game *game)
{
	float scale_horizontal = (game->scr_width  / 3) / game->map_width;
	float scale_vertical   = (game->scr_height / 3) / game->map_height;

	// Draw background
	draw_rect(
		game,
		0,
		0,
		scale_horizontal * game->map_width,
		scale_vertical * game->map_height,
		(t_rgba) {50, 50, 50, 255}
	);

	// Draw map tiles
	int tile_width  = 1 * scale_horizontal;
	int tile_height = 1 * scale_vertical;

	for (int map_y = 0; map_y < game->map_height; ++map_y) {
		for (int map_x = 0; map_x < game->map_width; ++map_x) {
			draw_rect(
				game,
				map_x * tile_width,
				map_y * tile_height,
				tile_width - 1,
				tile_height - 1, game->map[map_y][map_x] == '0'? (t_rgba) {0, 0, 0, 255} : (t_rgba) {175, 175, 175, 255}
			);
		}
	}

	// Draw player
	draw_rect(game, game->px * scale_horizontal - 4, game->py * scale_vertical - 4, 10, 10, (t_rgba) {255, 127, 0, 255});

	// Draw player direction
	draw_line_from_player(game, scale_horizontal, scale_vertical, 0);

	// Draw player rays
	// float raycast_angle_step = game->fov / game->scr_width;
	// for (float angle_offset = -game->fov / 2; angle_offset <= +game->fov / 2; angle_offset += raycast_angle_step) {
		// draw_line_from_player(game, scale_horizontal, scale_vertical, angle_offset);
	// }
}
