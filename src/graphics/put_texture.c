/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:17:10 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/17 19:15:58 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	calculate_wall_hit_x(float ray_angle, float player_x,
	float player_y, t_ray_hit *hit_info)
{
	float	wall_hit_x;

	if (hit_info->side == HIT_VERTICAL_WALL)
		wall_hit_x = player_y + cos(ray_angle) * hit_info->dist;
	else
		wall_hit_x = player_x + sin(ray_angle) * hit_info->dist;
	return (wall_hit_x - floor(wall_hit_x));
}

static mlx_texture_t	*return_texture(t_game *game,
	float ray_angle, t_ray_hit *hit_info)
{
	mlx_texture_t	*texture;

	texture = NULL;
	if (hit_info->side == HIT_VERTICAL_WALL)
	{
		if (sin(ray_angle) > 0)
			texture = game->tex_ea;
		else
			texture = game->tex_we;
	}
	else if (hit_info->side == HIT_HORIZONTAL_WALL)
	{
		if (cos(ray_angle) > 0)
			texture = game->tex_so;
		else
			texture = game->tex_no;
	}
	else
		texture = game->tex_door;
	return (texture);
}

static int	get_texture_color(mlx_texture_t *tex, t_ray_hit *hit_info,
	float wall_hit_x, int y)
{
	int		tex_x_offset;
	double	step;
	int		tex_y;
	int		color;

	tex_x_offset = (int)(wall_hit_x * tex->width) % tex->width;
	step = (double)tex->height / hit_info->wall_height;
	tex_y = (int)((y - hit_info->ceil_end_px) * step);
	clamp(&tex_y, 0, tex->height - 1);
	color = (tex->pixels[(tex_y * tex->width + tex_x_offset) * 4] << 24)
		| (tex->pixels[(tex_y * tex->width + tex_x_offset) * 4 + 1] << 16)
		| (tex->pixels[(tex_y * tex->width + tex_x_offset) * 4 + 2] << 8)
		| (tex->pixels[(tex_y * tex->width + tex_x_offset) * 4 + 3]);
	return (color);
}

void	draw_textured_wall(t_game *game, int x, float ray_angle,
	t_ray_hit *hit_info)
{
	mlx_texture_t	*texture;
	int				y;
	int				y_lim;
	float			wall_hit_x;

	texture = return_texture(game, ray_angle, hit_info);
	wall_hit_x = calculate_wall_hit_x(ray_angle, game->px, game->py, hit_info);
	y = game->scr_height / 2 - hit_info->wall_height / 2;
	y_lim = game->scr_height / 2 + hit_info->wall_height / 2;
	if (y < 0)
		y = 0;
	if (y_lim >= game->scr_height)
		y_lim = game->scr_height - 1;
	while (y < y_lim)
	{
		mlx_put_pixel(game->img, x, y, get_texture_color(texture, hit_info, wall_hit_x, y));
		y++;
	}
}
