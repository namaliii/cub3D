/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:55:35 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/16 17:27:00 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Draw a rectangle ignoring out of screen sections
void	draw_safe_rect(t_game *game, t_rect r)
{
	int	x;
	int	y;
	int	xlim;
	int	ylim;

	xlim = min2(r.posx + r.lenx, game->scr_width);
	ylim = min2(r.posy + r.leny, game->scr_height);
	x = max2(r.posx, 0);
	while (x < xlim)
	{
		y = max2(r.posy, 0);
		while (y < ylim)
		{
			mlx_put_pixel(game->img, x, y, rgba2color(r.color));
			++y;
		}
		++x;
	}
}

// Draw a rectangle. 
// Warning: out of screen values will segfault!
// If not sure, use draw_safe_rect() instead
void	draw_rect(t_game *game, t_rect r)
{
	int	x;
	int	y;
	int	lim_x;
	int	lim_y;

	lim_x = r.posx + r.lenx;
	lim_y = r.posy + r.leny;
	x = r.posx;
	while (x < lim_x)
	{
		y = r.posy;
		while (y < lim_y)
		{
			mlx_put_pixel(game->img, x, y, rgba2color(r.color));
			++y;
		}
		++x;
	}
}
