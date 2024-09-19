/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:42:26 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/17 19:17:51 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_dda_vars(t_dda_vars *v)
{
	v->step_x = 0;
	v->step_y = 0;
	v->dist_intersect_x = 0;
	v->dist_intersect_y = 0;
	v->dir_x = 0;
	v->dir_y = 0;
	v->map_x = 0;
	v->map_y = 0;
	v->init_side_dist_x = 0;
	v->init_side_dist_y = 0;
	v->hit = 0;
	v->side = 0;
	v->perp_wall_dist = 0;
}

static void	setup_vars(float angle, t_game *game, t_dda_vars *v)
{
	init_dda_vars(v);
	v->step_x = sin(angle);
	v->step_y = cos(angle);
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

static void	find_distance(t_game *game, t_dda_vars *v)
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
		if (is_wall(game, v->map_x, v->map_y))
			v->hit = 1;
	}
}

void	find_dist(float angle, t_game *game, t_ray_hit *p_ray_hit)
{
	t_dda_vars	v;

	setup_vars(angle, game, &v);
	find_distance(game, &v);
	if (v.side == HIT_VERTICAL_WALL)
		v.perp_wall_dist = (v.map_x - game->px + (1 - v.dir_x) / 2) / \
v.step_x;
	else if (v.side == HIT_HORIZONTAL_WALL)
		v.perp_wall_dist = (v.map_y - game->py + (1 - v.dir_y) / 2) / \
v.step_y;
	if (game->map[v.map_y][v.map_x] == DOOR_CLOSED_CHAR)
		v.side = HIT_DOOR;
	p_ray_hit->side = v.side;
	p_ray_hit->dist = v.perp_wall_dist;
}
