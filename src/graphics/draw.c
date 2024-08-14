/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:55:35 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/14 19:00:02 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Draw a rectangle ignoring out of screen sections
void	draw_safe_rect(t_game *game, int pos_x, int pos_y, int len_x, int len_y, t_rgba color)
{
	int x;
	int y;
	int xlim;
	int ylim;

	xlim = min_of(pos_x + len_x, game->scr_width);
	ylim = min_of(pos_y + len_y, game->scr_height);
	x = max_of(pos_x, 0);
	while (x < xlim)
	{
		y = max_of(pos_y, 0);
		while (y < ylim)
		{
			mlx_put_pixel(game->img, x, y, rgba2color(color));
			++y;
		}
		++x;
	}
}

// Draw a rectangle. 
// Warning: out of screen values will segfault!
// If not sure, use draw_safe_rect() instead
void	draw_rect(t_game *game, int pos_x, int pos_y, int len_x, int len_y, t_rgba color)
{
	int	x;
	int	y;
	int lim_x;
	int lim_y;

	lim_x = pos_x + len_x;
	lim_y = pos_y + len_y;
	x = pos_x;
	while (x < lim_x)
	{
		y = pos_y;
		while (y < lim_y)
		{
			mlx_put_pixel(game->img, x, y, rgba2color(color));
			++y;
		}
		++x;
	}
}
