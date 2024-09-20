/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:06:13 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/20 17:20:09 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_pixel(mlx_image_t *img, int x, int y, int color)
{
	if (x >= 0 && x < (int)img->width && y >= 0 && y < (int)img->height)
		mlx_put_pixel(img, x, y, color);
}

static void	draw_sprite(\
t_game *game, int cur_sprite_width, int cur_sprite_height, int frame_idx)
{
	int			x;
	int			y;
	int			x_pos;
	int			y_pos;
	uint32_t	color;

	x = 0;
	x_pos = (game->scr_width - cur_sprite_width) / 2 + game->sprite.sway_offset;
	y_pos = game->scr_height - cur_sprite_height;
	while (x < cur_sprite_width)
	{
		y = 0;
		while (y < cur_sprite_height)
		{
			color = get_mlx_texture_pixel(game->sprite.frames[frame_idx], x, y);
			if (!is_fully_transparent(color))
				put_pixel(game->img, x_pos + x, y_pos + y, color);
			y++;
		}
		x++;
	}
}

static void	update_sprite_animation(t_game *game, t_sprite *sprite)
{
	sprite->time_accumulator_sec += game->delta_time_sec;
	if (sprite->time_accumulator_sec > (1.0 / SPRITE_FRAME_RATE))
	{
		sprite->current_frame += sprite->direction;
		if (sprite->current_frame >= SPRITE_FRAMES)
		{
			sprite->current_frame = SPRITE_FRAMES - 2;
			sprite->direction = -1;
		}
		else if (sprite->current_frame < 0)
		{
			sprite->current_frame = 1;
			sprite->direction = 1;
		}
		sprite->time_accumulator_sec = 0.0;
	}
	sprite->sway_offset = sin(sprite->current_frame * M_PI / SPRITE_FRAMES);
}

void	handle_sprite_animation(t_game *game)
{
	update_sprite_animation(game, &game->sprite);
	draw_sprite(
		game,
		game->sprite.frames[game->sprite.current_frame]->width,
		game->sprite.frames[game->sprite.current_frame]->height,
		game->sprite.current_frame);
}
