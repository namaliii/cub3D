/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:38:28 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/13 09:59:53 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray_hit(t_ray_hit *p_ray_hit)
{
	p_ray_hit->side = -1;
	p_ray_hit->dist = 0.0;
	p_ray_hit->wall_start_px = 0;
	p_ray_hit->wall_end_px = 0;
	p_ray_hit->wall_height = 0;
}

static void	raycast_column(int x, t_game *game)
{
	t_ray_hit	hit_info;
	float		angle_rad;
	float		dist;
	int			ceiling_end_px;
	int			floor_start_px;

	init_ray_hit(&hit_info);
	angle_rad = (game->p_angle_rad + game->fov_rad / 2) - ((double) x / (double) game->scr_width) * game->fov_rad;
	find_dist(angle_rad, game, &hit_info);
	dist = hit_info.dist * cos(angle_rad - game->p_angle_rad);
	ceiling_end_px = (game->scr_height / 2.0) - (double) game->scr_height / dist;
	floor_start_px = game->scr_height - ceiling_end_px;
	hit_info.wall_start_px = ceiling_end_px;
	hit_info.wall_end_px = floor_start_px;
	hit_info.wall_height = floor_start_px - ceiling_end_px;
	draw_safe_rect(game, x, 0, 1, ceiling_end_px, game->color_ceiling);
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
