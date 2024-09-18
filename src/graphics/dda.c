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
	v->ray_dir_x = 0;
	v->ray_dir_y = 0;
	v->delta_dist_x = 0;
	v->delta_dist_y = 0;
	v->step_x = 0;
	v->step_y = 0;
	v->map_x = 0;
	v->map_y = 0;
	v->side_dist_x = 0;
	v->side_dist_y = 0;
	v->hit = 0;
	v->side = 0;
	v->perp_wall_dist = 0;
}

static void	setup_vars(float angle, t_game *game, t_dda_vars *v)
{
	init_dda_vars(v);
	v->ray_dir_x = sin(angle);
	v->ray_dir_y = cos(angle);
	v->delta_dist_x = sqrt(1 + pow((v->ray_dir_y / v->ray_dir_x), 2));
	v->delta_dist_y = sqrt(1 + pow((v->ray_dir_x / v->ray_dir_y), 2));
	if (v->ray_dir_x > 0)
		v->step_x = 1;
	else
		v->step_x = -1;
	if (v->ray_dir_y > 0)
		v->step_y = 1;
	else
		v->step_y = -1;
	v->map_x = (int) game->px;
	v->map_y = (int) game->py;
	if (v->step_x == 1)
		v->side_dist_x = (v->map_x + 1.0 - game->px) * v->delta_dist_x;
	else if (v->step_x == -1)
		v->side_dist_x = (game->px - v->map_x) * v->delta_dist_x;
	if (v->step_y == 1)
		v->side_dist_y = (v->map_y + 1.0 - game->py) * v->delta_dist_y;
	else if (v->step_y == -1)
		v->side_dist_y = (game->py - v->map_y) * v->delta_dist_y;
}

static void	find_distance(t_game *game, t_dda_vars *v)
{
	while (v->hit == 0)
	{
		if (v->side_dist_x < v->side_dist_y)
		{
			v->side_dist_x += v->delta_dist_x;
			v->map_x += v->step_x;
			v->side = HIT_VERTICAL_WALL;
		}
		else
		{
			v->side_dist_y += v->delta_dist_y;
			v->map_y += v->step_y;
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
		v.perp_wall_dist = (v.map_x - game->px + (1 - v.step_x) / 2) / \
v.ray_dir_x;
	else if (v.side == HIT_HORIZONTAL_WALL)
		v.perp_wall_dist = (v.map_y - game->py + (1 - v.step_y) / 2) / \
v.ray_dir_y;
	if (game->map[v.map_y][v.map_x] == DOOR_CLOSED_CHAR)
		v.side = HIT_DOOR;
	p_ray_hit->side = v.side;
	p_ray_hit->dist = v.perp_wall_dist;
}
