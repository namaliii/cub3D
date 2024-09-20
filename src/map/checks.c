/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:37:35 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/20 11:08:04 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_out_of_bounds(t_game *game, int x, int y)
{
	return (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height);
}

char	get_map_tile(t_game *game, int x, int y)
{
	if (is_out_of_bounds(game, x, y))
		return (TILE_OUT_OF_BOUNDS);
	else
		return (game->map[y][x]);
}

bool	is_tile_solid(char tile)
{
	return (tile == TILE_WALL || tile == TILE_DOOR_CLOSED_CHAR);
}

bool	is_map_tile_solid(t_game *game, int x, int y)
{
	return (is_tile_solid(get_map_tile(game, x, y)));
}
