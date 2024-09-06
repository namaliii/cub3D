/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:38:28 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/06 17:45:29 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	find_dist(float angle, t_game *game)
{
	float	dist;
	float	step_size;
	int		testx;
	int		testy;

	step_size = 0.025;
	dist = 0.0;
	do {
		dist += step_size;
		testx = (int) (game->px + sin(angle) * dist);
		testy = (int) (game->py + cos(angle) * dist);
	} while (!is_out_of_bounds(game, testx, testy) && !is_wall(game, testx, testy));
	return (dist);
}

static void	raycast_column(int x, t_game *game)
{
	float	angle_rad;
	float	dist;
	int		ceiling_end_px;
	int		floor_start_px;

	angle_rad = (game->p_angle_rad + game->fov_rad / 2) - ((double) x / (double) game->scr_width) * game->fov_rad;
	dist = find_dist(angle_rad, game) * cos(angle_rad - game->p_angle_rad);

	ceiling_end_px = (game->scr_height / 2.0) - (double) game->scr_height / dist;
	floor_start_px = game->scr_height - ceiling_end_px;

	//                   x, y             , xlen, ylen                             , color
	draw_safe_rect(game, x, 0             , 1   , ceiling_end_px                   , game->color_ceiling);
	// draw_safe_rect(game, x, ceiling_end_px, 1   , floor_start_px - ceiling_end_px  , (t_rgba) {200, 200, 200, 255});
	draw_textured_wall(game, x, ceiling_end_px, floor_start_px);
	// put_texture_pixel(game, ceiling_end_px, floor_start_px - ceiling_end_px);
	draw_safe_rect(game, x, floor_start_px, 1   , game->scr_height - floor_start_px, game->color_floor);
}

void	raycast(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->scr_width)
	{
		raycast_column(x, game);
		++x;
	}
}
