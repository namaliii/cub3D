/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:38:28 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/17 19:20:09 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_hit_info(t_ray_hit *info, int ceil_end_px, int floor_start_px)
{
	info->ceil_end_px = ceil_end_px;
	info->floor_start_px = floor_start_px;
	info->wall_height = floor_start_px - ceil_end_px;
}

static void	init_ray_hit(t_ray_hit *p_ray_hit)
{
	p_ray_hit->side = 0;
	p_ray_hit->dist = 0.0;
	p_ray_hit->ceil_end_px = 0;
	p_ray_hit->floor_start_px = 0;
	p_ray_hit->wall_height = 0;
}

static void	raycast_column(int x, t_game *game)
{
	t_ray_hit	hit_info;
	float		angle_rad;
	int			ceiling_end_px;
	int			floor_start_px;

	init_ray_hit(&hit_info);
	angle_rad = (game->p_angle_rad + game->fov_rad / 2) - ((double) x / (double) game->scr_width) * game->fov_rad;
	find_dist(angle_rad, game, &hit_info);
	hit_info.dist = hit_info.dist * cos(angle_rad - game->p_angle_rad);
	ceiling_end_px = (game->scr_height / 2.0) - (double) game->scr_height / hit_info.dist;
	floor_start_px = game->scr_height - ceiling_end_px;
	// TODO: Struct t_rect: x, y, xlen, ylen, color?
	draw_safe_rect(game, x, 0, 1, ceiling_end_px, game->color_ceiling);
	set_hit_info(&hit_info, ceiling_end_px, floor_start_px);
	draw_textured_wall(game, x, angle_rad, &hit_info);
	draw_safe_rect(game, x, floor_start_px, 1, game->scr_height - floor_start_px, game->color_floor);
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
