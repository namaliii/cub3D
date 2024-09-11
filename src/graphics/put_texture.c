/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:17:10 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/11 20:09:49 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	calculate_wall_hit_x(float ray_angle, float player_x,
	float player_y, t_ray_hit *hit_info)
{
	float	wall_hit_x;

	if (hit_info->side == 0)
		wall_hit_x = player_y + cos(ray_angle) * hit_info->dist;
	else
		wall_hit_x = player_x + sin(ray_angle) * hit_info->dist;
	return (wall_hit_x - floor(wall_hit_x));
}

mlx_texture_t	*return_texture(t_game *game,
	float ray_angle, t_ray_hit *hit_info)
{
	mlx_texture_t	*texture;

	texture = NULL;
	if (hit_info->side == 0)
	{
		if (sin(ray_angle) > 0)
			texture = game->tex_ea;
		else
			texture = game->tex_we;
	}
	else
	{
		if (cos(ray_angle) > 0)
			texture = game->tex_so;
		else
			texture = game->tex_no;
	}
	return (texture);
}

int	get_texture_color(mlx_texture_t *texture,
	t_ray_hit *hit_info, int wall_hit_x, int y)
{
	int		texture_x_offset;
	double	step;
	int		texture_y;
	int		color;

	texture_x_offset = (int)(wall_hit_x * texture->width) % texture->width;
	step = (double)texture->height / hit_info->wall_height;
	texture_y = (int)((y - hit_info->wall_start_px) * step);
	texture_y = min2(max2(texture_y, 0), texture->height - 1);
	color = (texture->pixels
		[(texture_y * texture->width + texture_x_offset) * 4] << 24)
		| (texture->pixels
		[(texture_y * texture->width + texture_x_offset) * 4 + 1] << 16)
		| (texture->pixels
		[(texture_y * texture->width + texture_x_offset) * 4 + 2] << 8)
		| (texture->pixels
		[(texture_y * texture->width + texture_x_offset) * 4 + 3]);
	return (color);
}

void	draw_textured_wall(t_game *game, int x,
	float ray_angle, t_ray_hit *hit_info)
{
	mlx_texture_t	*texture;
	int				y;
	int				color;
	float			wall_hit_x;

	texture = return_texture(game, ray_angle, hit_info);
	y = hit_info->wall_start_px;
	wall_hit_x = calculate_wall_hit_x(ray_angle, game->px, game->py, hit_info);
	while (y < hit_info->wall_end_px)
	{
		color = get_texture_color(texture, hit_info, wall_hit_x, y);
		if (x >= 0 && x < game->scr_width && y >= 0 && y < game->scr_height)
			mlx_put_pixel(game->img, x, y, color);
		y++;
	}
}

// void	draw_textured_wall(t_game *game, int x, float ray_angle,
// 	t_ray_hit *hit_info)
// {
// 	float			wall_hit_x;
// 	mlx_texture_t	*texture;
// 	int				texture_x_offset;
// 	int				wall_height;
// 	double			step;
// 	int				y;
// 	int 			texture_y;
// 	int 			color;

// 	wall_hit_x = calculate_wall_hit_x(ray_angle, game->px, game->py, hit_info);
// 	texture = return_texture(game, ray_angle, hit_info);
// 	texture_x_offset = (int)(wall_hit_x * texture->width) % texture->width;
// 	wall_height = hit_info->wall_end_px - hit_info->wall_start_px;
// 	step = (double)texture->height / wall_height;
// 	y = hit_info->wall_start_px;
// 	while (y < hit_info->wall_end_px)
// 	{
// 		texture_y = (int)((y - hit_info->wall_start_px) * step);
// 		texture_y = min2(max2(texture_y, 0), texture->height - 1);
// 		color = (texture->pixels[(texture_y * texture->width + texture_x_offset) * 4] << 24)
// 			| (texture->pixels[(texture_y * texture->width + texture_x_offset) * 4 + 1] << 16)
// 			| (texture->pixels[(texture_y * texture->width + texture_x_offset) * 4 + 2] << 8)
// 			| (texture->pixels[(texture_y * texture->width + texture_x_offset) * 4 + 3]);
// 		if (x < game->scr_width && y < game->scr_height && x >= 0 && y >= 0)
// 			mlx_put_pixel(game->img, x, y, color);
// 		y++;
// 	}
// }