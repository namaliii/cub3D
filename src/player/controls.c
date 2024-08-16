/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:43:24 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/16 17:22:44 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	normalize_vector(t_vec2d *v)
{
	const float	magnitude = sqrtf(v->x * v->x + v->y * v->y);
	const float	inv_sqrt = 1.0 / magnitude;

	if (magnitude > 0)
	{
		v->x = v->x * inv_sqrt;
		v->y = v->y * inv_sqrt;
	}
}

static void	handle_door(t_game *game)
{
	const t_vec2d	direction_offsets[DIRECTION_OFFSET_COUNT] = \
{{1,0}, {0, 1}, {1, 1}, {-1, 0}, {-1, 1}, {-1, -1}, {0, -1}, {1, -1}};
	int				check_x;
	int				check_y;
	int				i;
	
	i = 0;
	while (i < DIRECTION_OFFSET_COUNT)
	{
		check_x = game->px + direction_offsets[i].x;
		check_y = game->py + direction_offsets[i].y;
		if (check_x >= 0 && check_x < game->map_width
			&& check_y >= 0 && check_y < game->map_height)
		{
			if (game->map[check_y][check_x] == DOOR_OPENED_CHAR)
				game->map[check_y][check_x] = DOOR_CLOSED_CHAR;
			else if (game->map[check_y][check_x] == DOOR_CLOSED_CHAR)
				game->map[check_y][check_x] = DOOR_OPENED_CHAR;
		}
		++i;
	}
}

static void	handle_movement_keys(t_game *game, t_vec2d *pos_change)
{
	if (mlx_is_key_down(game->window, MLX_KEY_W))
	{
		pos_change->x += sin(game->p_angle_rad);
		pos_change->y += cos(game->p_angle_rad);
	}
	if (mlx_is_key_down(game->window, MLX_KEY_S))
	{
		pos_change->x -= sin(game->p_angle_rad);
		pos_change->y -= cos(game->p_angle_rad);
	}
	if (mlx_is_key_down(game->window, MLX_KEY_A))
	{
		pos_change->x += sin(game->p_angle_rad + deg2rad(90.0));
		pos_change->y += cos(game->p_angle_rad + deg2rad(90.0));
	}
	if (mlx_is_key_down(game->window, MLX_KEY_D))
	{
		pos_change->x += sin(game->p_angle_rad - deg2rad(90.0));
		pos_change->y += cos(game->p_angle_rad - deg2rad(90.0));
	}
}

void	handle_movement(t_game *game)
{
	t_vec2d	pos_change;

	pos_change = (t_vec2d) {0, 0};
	if (mlx_is_key_down(game->window, MLX_KEY_ESCAPE))
	{
		mlx_delete_image(game->window, game->img);
		mlx_close_window(game->window);
		mlx_terminate(game->window);
		exit(EXIT_SUCCESS);
	}
	if (mlx_is_key_down(game->window, MLX_KEY_E)
		|| mlx_is_key_down(game->window, MLX_KEY_RIGHT))
		game->p_angle_rad -= TURN_ANGLE;
	if (mlx_is_key_down(game->window, MLX_KEY_Q)
		|| mlx_is_key_down(game->window, MLX_KEY_LEFT))
		game->p_angle_rad += TURN_ANGLE;
	handle_movement_keys(game, &pos_change);
	normalize_vector(&pos_change);
	game->px += pos_change.x * WALK_SPEED;
	game->py += pos_change.y * WALK_SPEED;
}

void	keyboard_hook(mlx_key_data_t key, void *param)
{
	t_game	*game;

	game = (t_game *) param;
	if (key.key == MLX_KEY_SPACE && key.action == MLX_PRESS)
		handle_door(game);
}
