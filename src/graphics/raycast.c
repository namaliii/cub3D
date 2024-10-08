/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:38:28 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/20 15:44:52 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Processes angles and returns a fisheye adjusted distance.
// Original distance parameter remains the same.
static float	fisheye_adjst(\
t_game *game, t_ray_hit *hit_info, float ray_angle)
{
	return (hit_info->dist * cos(ray_angle - game->p_angle_rad));
}

static void	set_hit_info(t_ray_hit *info, int ceil_end_px, int floor_start_px)
{
	info->ceil_end_px = ceil_end_px;
	info->floor_start_px = floor_start_px;
	info->wall_height = floor_start_px - ceil_end_px;
}

static void	raycast_column(int x, t_game *game)
{
	t_ray_hit	hit_info;
	float		angle_rad;
	int			ceilng_end_px;
	int			floor_start_px;

	ft_bzero(&hit_info, sizeof(t_ray_hit));
	angle_rad = (game->p_angle_rad + game->fov_rad / 2)
		- ((float) x / game->scr_width) * game->fov_rad;
	find_dist(angle_rad, game, &hit_info);
	ceilng_end_px = (game->scr_height / 2.0)
		- (float) game->scr_height / fisheye_adjst(game, &hit_info, angle_rad);
	floor_start_px = game->scr_height - ceilng_end_px;
	draw_safe_rect(game, (t_rect){x, 0, 1, ceilng_end_px, game->color_ceiling});
	set_hit_info(&hit_info, ceilng_end_px, floor_start_px);
	draw_textured_wall(game, x, angle_rad, &hit_info);
	draw_safe_rect(game, (t_rect){x, floor_start_px,
		1, game->scr_height - floor_start_px, game->color_floor});
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
