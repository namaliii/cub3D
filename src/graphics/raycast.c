/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:38:28 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/12 15:46:50 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hit_info_init(t_ray_hit *hit_info)
{
	if (hit_info != NULL)
	{
		hit_info->side = -1;
		hit_info->dist = 0.0;
		hit_info->wall_start_px = 0;
		hit_info->wall_end_px = 0;
		hit_info->wall_height = 0;
	}
}

static t_ray_hit	*find_dist(float angle, t_game *game)
{
	t_ray_hit	*hit_info;
	float		step_size;
	int			testx;
	int			testy;
	int			prevx;
	int			prevy;

	hit_info = malloc(sizeof(t_ray_hit));
	hit_info_init(hit_info);
	step_size = 0.025;
	prevx = game->px;
	prevy = game->py;
	do {
		hit_info->dist += step_size;
		testx = (int) (game->px + sin(angle) * hit_info->dist);
		testy = (int) (game->py + cos(angle) * hit_info->dist);
		if (is_wall(game, testx, testy))
		{
			if (prevx != testx)
				hit_info->side = 0;
			else
				hit_info->side = 1;
			break ;
		}
		prevx = testx;
		prevy = testy;
	} while (!is_out_of_bounds(game, testx, testy));
	return (hit_info);
}

static void	raycast_column(int x, t_game *game)
{
	t_ray_hit	*hit_info;
	float		angle_rad;
	float		dist;
	int			ceiling_end_px;
	int			floor_start_px;

	angle_rad = (game->p_angle_rad + game->fov_rad / 2) - ((double) x / (double) game->scr_width) * game->fov_rad;
	hit_info = find_dist(angle_rad, game);
	dist = hit_info->dist * cos(angle_rad - game->p_angle_rad);
	ceiling_end_px = (game->scr_height / 2.0) - (double) game->scr_height / dist;
	floor_start_px = game->scr_height - ceiling_end_px;
	hit_info->wall_start_px = ceiling_end_px;
	hit_info->wall_end_px = floor_start_px;
	hit_info->wall_height = floor_start_px - ceiling_end_px;
	//                   x, y             , xlen, ylen                             , color
	draw_safe_rect(game, x, 0             , 1   , ceiling_end_px                   , game->color_ceiling);
	// draw_safe_rect(game, x, ceiling_end_px, 1   , floor_start_px - ceiling_end_px  , (t_rgba) {200, 200, 200, 255});
	draw_textured_wall(game, x, angle_rad, hit_info);
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
