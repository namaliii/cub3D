/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:38:28 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/13 17:46:24 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	find_dist(float angle, t_game *game)
{
	float	dist;
	float	step_size;
	int		testx;
	int		testy;

	step_size = 0.1;
	dist = -step_size;
	do {
		dist += step_size;
		testx = (int) (game->px + sin(angle) * dist);
		testy = (int) (game->py + cos(angle) * dist);
	} while (!is_out_of_bounds(game, testx, testy) && !is_wall(game, testx, testy));
	return (dist);
}

static void	draw_column(int x, t_game *game)
{
	float	angle;
	float	dist;
	int		ceiling_start_px;
	int		floor_start_px;
	int		y;

	// Calculate ray angle
	angle = (game->p_angle - game->fov / 2) + ((double) x / game->scr_width) * game->fov;
	
	// Find distance
	dist = find_dist(angle, game);

	// Draw
	ceiling_start_px = (game->scr_height / 2.0) - (double) game->scr_height / dist;
	floor_start_px = game->scr_height - ceiling_start_px;

	y = 0;
	while (y < game->scr_height)
	{
		if (y < ceiling_start_px)
		{
			mlx_put_pixel(game->img, x, y, rgba2color(game->color_ceiling));
		}
		else if (y >= ceiling_start_px && y < floor_start_px)
		{
			mlx_put_pixel(game->img, x, y, rgba2color((t_rgba) {200, 200, 200, 255}));
		}
		else
		{
			mlx_put_pixel(game->img, x, y, rgba2color(game->color_floor));
		}
		++y;
	}
}

void	draw(t_game *game)
{
	int	x;
	
	mlx_delete_image(game->window, game->img);
	game->img = mlx_new_image(game->window, game->scr_width, game->scr_height);
	mlx_image_to_window(game->window, game->img, 0, 0);
	x = 0;
	while (x < game->scr_width)
	{
		draw_column(x, game);
		++x;
	}
	debug_print(game);
}
