/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:48:50 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/13 20:21:51 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_pos_walkable(t_game *game, t_vec2d *pos_change, int angle_offset)
{
	(void)game;
	(void)pos_change;
	(void)angle_offset;
	return (1);
}

// Check if the direction of `mv_dir` unit vector walkable
int	is_walkable(t_game *game, t_vec2d *mv_dir)
{
	if (is_pos_walkable(game, vec2d_mult_by_scalar(mv_dir, WALK_SPEED), 0)
		&& is_pos_walkable(game, vec2d_mult_by_scalar(mv_dir, WALK_SPEED), 55)
		&& is_pos_walkable(game, vec2d_mult_by_scalar(mv_dir, WALK_SPEED), -55))
		return (1);
	return (0);
}
