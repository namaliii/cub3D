/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:38:28 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/12 17:16:33 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_column(int x, t_screen *screen, t_map *map, t_player *player)
{
	
}

void	raycast(t_screen *screen, t_map *map, t_player *player)
{
	int	x;

	x = 0;
	while (x < screen->width)
	{
		draw_column(x, screen, player, map);
		++x;
	}
}
