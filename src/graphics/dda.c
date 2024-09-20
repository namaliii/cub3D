/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:42:26 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/20 15:44:25 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	setup_vars(float angle_rad, t_game *game, t_dda_vars *v)
{
	ft_bzero(v, sizeof(t_dda_vars));
	v->step_x = sin(angle_rad);
	v->step_y = cos(angle_rad);
	v->dist_intersect_x = sqrt(1 + pow((v->step_y / v->step_x), 2));
	v->dist_intersect_y = sqrt(1 + pow((v->step_x / v->step_y), 2));
	if (v->step_x > 0)
		v->dir_x = 1;
	else
		v->dir_x = -1;
	if (v->step_y > 0)
		v->dir_y = 1;
	else
		v->dir_y = -1;
	v->map_x = (int) game->px;
	v->map_y = (int) game->py;
	if (v->dir_x == 1)
		v->init_side_dist_x = (v->map_x + 1 - game->px) * v->dist_intersect_x;
	else if (v->dir_x == -1)
		v->init_side_dist_x = (game->px - v->map_x) * v->dist_intersect_x;
	if (v->dir_y == 1)
		v->init_side_dist_y = (v->map_y + 1 - game->py) * v->dist_intersect_y;
	else if (v->dir_y == -1)
		v->init_side_dist_y = (game->py - v->map_y) * v->dist_intersect_y;
}

static void	find_distance(t_game *game, t_dda_vars *v, t_ray_hit *p_ray_hit)
{
	while (v->hit == 0)
	{
		if (v->init_side_dist_x < v->init_side_dist_y)
		{
			v->init_side_dist_x += v->dist_intersect_x;
			v->map_x += v->dir_x;
			v->side = HIT_VERTICAL_WALL;
		}
		else
		{
			v->init_side_dist_y += v->dist_intersect_y;
			v->map_y += v->dir_y;
			v->side = HIT_HORIZONTAL_WALL;
		}
		p_ray_hit->hit_tile_type = get_map_tile(game, v->map_x, v->map_y);
		if (is_tile_solid(p_ray_hit->hit_tile_type))
			v->hit = 1;
	}
}

void	find_dist(float angle_rad, t_game *game, t_ray_hit *p_ray_hit)
{
	t_dda_vars	v;

	setup_vars(angle_rad, game, &v);
	find_distance(game, &v, p_ray_hit);
	if (v.side == HIT_VERTICAL_WALL)
		v.perp_wall_dist = (v.map_x - game->px + (1 - v.dir_x) / 2) / \
v.step_x;
	else if (v.side == HIT_HORIZONTAL_WALL)
		v.perp_wall_dist = (v.map_y - game->py + (1 - v.dir_y) / 2) / \
v.step_y;
	p_ray_hit->side = v.side;
	p_ray_hit->dist = v.perp_wall_dist;
}
