/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:43:24 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/13 22:00:13 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Get a unit vector towards movement direction.
// `pos_change` will be set as the result.
static void	get_movement_direction(t_game *game, t_vec2d *pos_change)
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
	vec2d_normalize(pos_change);
}

void	handle_movement(t_game *game)
{
	t_vec2d	pos_change;

	pos_change = (t_vec2d){0, 0};
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
	get_movement_direction(game, &pos_change);
	vec2d_mult_by_scalar(&pos_change, WALK_SPEED);
	// if (!is_wall(game, game->px + COLLISION_DIST * pos_change.x, game->py))
		game->px = game->px + pos_change.x;
	// if (!is_wall(game, game->px, game->py + COLLISION_DIST * pos_change.y))
		game->py = game->py + pos_change.y;
}

static void	handle_door(t_game *game)
{
	const t_vec2d	direction_offsets[DIRECTION_OFFSET_COUNT] = \
	{{1, 0}, {0, 1}, {1, 1}, {-1, 0}, {-1, 1}, {-1, -1}, {0, -1}, {1, -1}};
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

void	keyboard_hook(mlx_key_data_t key, void *param)
{
	t_game	*game;

	game = (t_game *) param;
	if (key.key == MLX_KEY_SPACE && key.action == MLX_PRESS)
		handle_door(game);
}

void	mouse_move_hook(double x, double y, void *param)
{
	t_game	*game;
	double	center_x;

	(void)y;
	game = (t_game *)param;
	center_x = game->scr_width / 2.0;
	game->p_angle_rad -= (x - center_x) * MOUSE_SENSITIVITY;
	mlx_set_mouse_pos(game->window, center_x, game->scr_height / 2);
}
