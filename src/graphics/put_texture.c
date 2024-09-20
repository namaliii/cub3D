/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:17:10 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/20 15:44:45 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	calculate_wall_hit_x(\
t_game *game, float ray_angle, t_ray_hit *hit_info)
{
	float	wall_hit_x;

	if (hit_info->side == HIT_VERTICAL_WALL)
		wall_hit_x = game->py + cos(ray_angle) * hit_info->dist;
	else
		wall_hit_x = game->px + sin(ray_angle) * hit_info->dist;
	return (wall_hit_x - floor(wall_hit_x));
}

static mlx_texture_t	*return_texture(\
t_game *game, float ray_angle, t_ray_hit *hit_info)
{
	mlx_texture_t	*texture;

	texture = NULL;
	if (hit_info->hit_tile_type == TILE_DOOR_CLOSED_CHAR)
		texture = game->tex_door;
	else if (hit_info->side == HIT_VERTICAL_WALL)
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

static uint32_t	get_texture_color(mlx_texture_t *tex, t_ray_hit *hit_info,
	float wall_hit_x, int y)
{
	int		tex_x;
	double	step;
	int		tex_y;

	step = (double)tex->height / hit_info->wall_height;
	tex_x = (int)(wall_hit_x * tex->width) % tex->width;
	tex_y = (int)((y - hit_info->ceil_end_px) * step);
	clamp(&tex_y, 0, tex->height - 1);
	return (get_mlx_texture_pixel(tex, tex_x, tex_y));
}

void	draw_textured_wall(t_game *game, int x, float ray_angle,
	t_ray_hit *hit_info)
{
	mlx_texture_t	*texture;
	int				y;
	int				y_lim;
	float			wall_hit_x;

	texture = return_texture(game, ray_angle, hit_info);
	wall_hit_x = calculate_wall_hit_x(game, ray_angle, hit_info);
	y = game->scr_height / 2 - hit_info->wall_height / 2;
	y_lim = game->scr_height / 2 + hit_info->wall_height / 2;
	if (y < 0)
		y = 0;
	if (y_lim >= game->scr_height)
		y_lim = game->scr_height - 1;
	while (y < y_lim)
	{
		mlx_put_pixel(game->img, x, y,
			get_texture_color(texture, hit_info, wall_hit_x, y));
		y++;
	}
}
