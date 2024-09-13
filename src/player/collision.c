/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:48:50 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/13 21:26:11 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_pos_walkable(t_game *game, t_vec2d *pos_change, int angle_offset)
{
	vec2d_rot_ccw(pos_change, angle_offset);
	if (is_wall(game, game->px + pos_change->x, game->py + pos_change->y))
		return (0);
	return (1);
}

// Check if the direction of `mv_dir` unit vector walkable
int	is_walkable(t_game *g, t_vec2d mv_dir)
{
	const float multiplier = 1;

	if (is_pos_walkable(g, vec2d_mult_by_scalar(&mv_dir, multiplier * WALK_SPEED), 0)
		// && is_pos_walkable(g, vec2d_mult_by_scalar(&mv_dir, multiplier * WALK_SPEED), 55)
		// && is_pos_walkable(g, vec2d_mult_by_scalar(&mv_dir, multiplier * WALK_SPEED), -55)
	)
		return (1);
	return (0);
}
