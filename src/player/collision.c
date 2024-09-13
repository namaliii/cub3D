/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:48:50 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/13 20:02:45 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// offset: -55, 0, 55
int	does_ray_collide(int offset)
{
	(void)offset;
	return 1;
}

// `pos_change` added to the player position will be the new location,
// check if it is suitable to move there.
int	is_walkable(t_game *game, t_vec2d *pos_change)
{
	(void)game;
	(void)pos_change;
	// d = WALK_SPEED
	// alpha = 55



	// straight

	// left

	// right
	return 1;
}
