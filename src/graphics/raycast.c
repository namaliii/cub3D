/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:38:28 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/11 04:42:11 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static float	find_dist(float angle, t_game *game)
// {
// 	float	dist;
// 	float	step_size;
// 	int		testx;
// 	int		testy;

// 	step_size = 0.025;
// 	dist = 0.0;
// 	do {
// 		dist += step_size;
// 		testx = (int) (game->px + sin(angle) * dist);
// 		testy = (int) (game->py + cos(angle) * dist);
// 	} while (!is_out_of_bounds(game, testx, testy) && !is_wall(game, testx, testy));
// 	return (dist);
// }

static float	find_dist(float angle, t_game *game)
{
	float ray_dir_x = sin(angle);
	float ray_dir_y = cos(angle);
	
	float delta_dist_x = sqrt(1 + pow((ray_dir_y / ray_dir_x), 2));
	float delta_dist_y = sqrt(1 + pow((ray_dir_x / ray_dir_y), 2));
	
	int step_x = (ray_dir_x > 0 ? 1 : -1);
	int step_y = (ray_dir_y > 0 ? 1 : -1);
	
	int map_x = (int) game->px;
	int map_y = (int) game->py;

	float side_dist_x = 0;
	if (step_x == 1)       side_dist_x = (map_x + 1.0 - game->px) * delta_dist_x;
	else if (step_x == -1) side_dist_x = (game->px - map_x) * delta_dist_x;

	float side_dist_y = 0;
	if (step_y == 1)       side_dist_y = (map_y + 1.0 - game->py) * delta_dist_y;
	else if (step_y == -1) side_dist_y = (game->py - map_y) * delta_dist_y;

	int hit  = 0;
	int side = 0;
	while (hit == 0)
	{
		// Jump to the next map square, X or Y direction
		if (side_dist_x < side_dist_y) {
			side_dist_x += delta_dist_x;
			map_x += step_x;
			side = 0; // hit a vertical wall
		} else {
			side_dist_y += delta_dist_y;
			map_y += step_y;
			side = 1; // hit a horizontal wall
		}
		
		if (is_wall(game, map_x, map_y))
			hit = 1;
	}

	float perp_wall_dist = 0;
	if (side == 0)
		perp_wall_dist = (map_x - game->px + (1 - step_x) / 2) / ray_dir_x;
	else if (side == 1)
		perp_wall_dist = (map_y - game->py + (1 - step_y) / 2) / ray_dir_y;
	
	return perp_wall_dist;
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
	draw_safe_rect(game, x, ceiling_end_px, 1   , floor_start_px - ceiling_end_px  , (t_rgba) {200, 200, 200, 255});
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
