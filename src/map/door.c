/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:02:54 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/20 11:05:39 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Toggle the door open/close if there is one in the provided coordinates
void	toggle_door(t_game *game, int door_x, int door_y)
{
	if (game->map[door_y][door_x] == TILE_DOOR_OPENED_CHAR)
		game->map[door_y][door_x] = TILE_DOOR_CLOSED_CHAR;
	else if (game->map[door_y][door_x] == TILE_DOOR_CLOSED_CHAR)
		game->map[door_y][door_x] = TILE_DOOR_OPENED_CHAR;
}

// Toggle the door open/close if there is one in the provided coordinates
// Perform a bound check beforehand
void	toggle_door_safe(t_game *game, int door_x, int door_y)
{
	if (!is_out_of_bounds(game, door_x, door_y))
		toggle_door(game, door_x, door_y);
}
