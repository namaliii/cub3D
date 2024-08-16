/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:37:35 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/16 14:37:51 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_out_of_bounds(t_game *game, int x, int y)
{
	return (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height);
}

// Return whether character at (x, y) of map should stop a ray or not
bool	is_wall(t_game *game, int x, int y)
{
	const char	*solid_elements = SOLID_ELEMENTS;
	int		lim;
	int		i;

	lim = ft_strlen(solid_elements);
	i = 0;
	while (i < lim)
	{
		if (solid_elements[i] == game->map[y][x])
			return (true);
		++i;
	}
	return (false);
}
