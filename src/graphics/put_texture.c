/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:17:10 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/05 20:38:25 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_texture_pixel(t_game *game, int wall_start_px, int wall_end_px)
{
	int	width;
	int	height;
	int	color;
	int	y;
	int	x;

	x = 0;
	y = wall_start_px;
	width = game->tex_no->width;
	height = game->tex_no->height;
	while (x < width)
	{
		while (y < wall_end_px)
		{
			color = (game->tex_no->pixels[(y * width + x) * 4] << 24)
				| (game->tex_no->pixels[(y * width + x) * 4 + 1] << 16)
				| (game->tex_no->pixels[(y * width + x) * 4 + 2] << 8)
				| (game->tex_no->pixels[(y * width + x) * 4 + 3]);
			mlx_put_pixel(game->img, x, y, color);
			y++;
		}
		x++;
	}
}
