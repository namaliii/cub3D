/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:17:10 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/06 18:14:35 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	put_texture_pixel(t_game *game, int wall_start_px, int wall_end_px)
// {
// 	int	width;
// 	int	height;
// 	int	color;
// 	int	y;
// 	int	x;

// 	x = 0;
// 	y = wall_start_px;
// 	width = game->tex_no->width;
// 	height = game->tex_no->height;
// 	while (x < width)
// 	{
// 		while (y < wall_end_px)
// 		{
// 			color = (game->tex_no->pixels[(y * width + x) * 4] << 24)
// 				| (game->tex_no->pixels[(y * width + x) * 4 + 1] << 16)
// 				| (game->tex_no->pixels[(y * width + x) * 4 + 2] << 8)
// 				| (game->tex_no->pixels[(y * width + x) * 4 + 3]);
// 			mlx_put_pixel(game->img, x, y, color);
// 			y++;
// 		}
// 		x++;
// 	}
// }
void	draw_textured_wall(t_game *game, int x, int wall_start_px, int wall_end_px)
{
    mlx_texture_t *texture = game->tex_no;
    int texture_width = texture->width;
    int texture_height = texture->height;
    int wall_height = wall_end_px - wall_start_px;
    double step = (double)texture_height / wall_height;
    // double step = (double)wall_height / texture_height;
    int texture_x = x % texture_width;
    int y = wall_start_px;
    while (y < wall_end_px)
    {
        int texture_y = step * (int)(y - wall_start_px);
        texture_y = min2(max2(texture_y, 0), texture_height - 1);
        int color = (texture->pixels[(texture_y * texture_width + texture_x) * 4] << 24)
                    | (texture->pixels[(texture_y * texture_width + texture_x) * 4 + 1] << 16)
                    | (texture->pixels[(texture_y * texture_width + texture_x) * 4 + 2] << 8)
                    | (texture->pixels[(texture_y * texture_width + texture_x) * 4 + 3]);
		if (x < SCREEN_WIDTH && y < SCREEN_HEIGHT && x > 0 && y > 0)
    		mlx_put_pixel(game->img, x, y, color);
        y++;
    }
}
