/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:38:28 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/12 20:36:41 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	find_dist(float angle, t_map *map, t_player *player)
{
	float	dist;
	float	step_size;
	int		testx;
	int		testy;

	step_size = 0.1;
	dist = -step_size;
	do {
		dist += step_size;
		testx = (int) (player->posx + sin(angle) * dist);
		testy = (int) (player->posy + cos(angle) * dist);
	} while (!is_out_of_bounds(map, testx, testy) && !is_wall(map, testx, testy));
	return (dist);
}

static void	draw_column(int x, t_screen *screen, t_map *map, t_player *player)
{
	float	angle;
	float	dist;
	int		ceiling_start_px;
	int		floor_start_px;
	int		y;

	// Calculate ray angle
	angle = (player->angle - screen->fov / 2) + ((double) x / screen->width) * screen->fov;
	
	// Find distance
	dist = find_dist(angle, map, player);

	// Draw
	ceiling_start_px = (screen->height / 2.0) - (double) screen->height / dist;
	floor_start_px = screen->height - ceiling_start_px;

	y = 0;
	while (y < screen->height)
	{
		if (y < ceiling_start_px)
		{
			mlx_put_pixel(screen->img, x, y, rgba2color(map->color_ceiling));
		}
		else if (y >= ceiling_start_px && y < floor_start_px)
		{
			mlx_put_pixel(screen->img, x, y, rgba2color((t_rgba) {200, 200, 200, 255}));
		}
		else
		{
			mlx_put_pixel(screen->img, x, y, rgba2color(map->color_floor));
		}
		++y;
	}
}

void	raycast(t_screen *screen, t_map *map, t_player *player)
{
	int	x;

	x = 0;
	while (x < screen->width)
	{
		draw_column(x, screen, map, player);
		++x;
	}
}
