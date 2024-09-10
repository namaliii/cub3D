/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:17:10 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/10 22:03:30 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	calculate_wall_hit_x(float ray_angle, float player_x, float player_y, t_int_float both)
{
	float	wall_hit_x;

	if (both.side == 0)
		wall_hit_x = player_y + cos(ray_angle) * both.dist;
	else
		wall_hit_x = player_x + sin(ray_angle) * both.dist;
	return (wall_hit_x - floor(wall_hit_x));
}

int	calculate_texture_x_offset(float wall_hit_x, t_game *game)
{
	mlx_texture_t	*texture;

	texture = game->tex_no;
	int texture_width = texture->width;
	int texture_x_offset = (int)(wall_hit_x * texture_width) % texture_width;
	return texture_x_offset;
}

void	draw_textured_wall(t_game *game, int x, int wall_start_px, int wall_end_px, float ray_angle, t_int_float both)
{
	float wall_hit_x = calculate_wall_hit_x(ray_angle, game->px, game->py, both);
	int texture_x_offset = calculate_texture_x_offset(wall_hit_x, game);
	mlx_texture_t *texture = NULL;
	// printf("side: %d\n", both.side);
	// printf("vector x: %f\n", both.vector.x);
	// printf("vector y: %f\n", both.vector.y);
    if (both.side == 0)  // Horizontal wall hit (aligned with Y-axis)
    {
        if (sin(ray_angle) > 0)  // Ray direction on X-axis
            texture = game->tex_ea; // East wall
        else
            texture = game->tex_we; // West wall
    }
    else  // Vertical wall hit (aligned with X-axis)
    {
        if (cos(ray_angle) > 0)  // Ray direction on Y-axis
            texture = game->tex_so; // South wall
        else
            texture = game->tex_no; // North wall
    }
	int texture_width = texture->width;
	int texture_height = texture->height;
	int wall_height = wall_end_px - wall_start_px;
	double step = (double)texture_height / wall_height;
	int y = wall_start_px;
	// printf("Player ray angle: %f\n", game->p_angle_rad);
	while (y < wall_end_px)
	{
		int texture_y = (int)((y - wall_start_px) * step);
		texture_y = min2(max2(texture_y, 0), texture_height - 1);
		int color = (texture->pixels[(texture_y * texture_width + texture_x_offset) * 4] << 24)
					| (texture->pixels[(texture_y * texture_width + texture_x_offset) * 4 + 1] << 16)
					| (texture->pixels[(texture_y * texture_width + texture_x_offset) * 4 + 2] << 8)
					| (texture->pixels[(texture_y * texture_width + texture_x_offset) * 4 + 3]);
		if (x < game->scr_width && y < game->scr_height && x >= 0 && y >= 0)
			mlx_put_pixel(game->img, x, y, color);
		y++;
	}
}
