/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:43:24 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/16 14:09:34 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_quit(t_game *game)
{
	mlx_delete_image(game->window, game->img);
	mlx_close_window(game->window);
	mlx_terminate(game->window);
	exit(EXIT_SUCCESS);
}

static void	handle_movement_keys(t_game *game, t_vec2d *pos_change)
{
	if (mlx_is_key_down(game->window, MLX_KEY_W))
	{
		pos_change->x += sin(game->p_angle_rad) * WALK_SPEED;
		pos_change->y += cos(game->p_angle_rad) * WALK_SPEED;	
	}
	if (mlx_is_key_down(game->window, MLX_KEY_S))
	{
		pos_change->x -= sin(game->p_angle_rad) * WALK_SPEED;
		pos_change->y -= cos(game->p_angle_rad) * WALK_SPEED;
	}
	if (mlx_is_key_down(game->window, MLX_KEY_A))
	{
		pos_change->x += sin(game->p_angle_rad + deg2rad(90.0)) * WALK_SPEED;
		pos_change->y += cos(game->p_angle_rad + deg2rad(90.0)) * WALK_SPEED;
	}
	if (mlx_is_key_down(game->window, MLX_KEY_D))
	{
		pos_change->x += sin(game->p_angle_rad - deg2rad(90.0)) * WALK_SPEED;
		pos_change->y += cos(game->p_angle_rad - deg2rad(90.0)) * WALK_SPEED;
	}
}

void	handle_movement(t_game *game)
{
	t_vec2d	pos_change;

	pos_change = (t_vec2d) {0, 0};
	if (mlx_is_key_down(game->window, MLX_KEY_ESCAPE))
		handle_quit(game);
	if (mlx_is_key_down(game->window, MLX_KEY_E)
		|| mlx_is_key_down(game->window, MLX_KEY_RIGHT))
		game->p_angle_rad -= TURN_ANGLE;
	if (mlx_is_key_down(game->window, MLX_KEY_Q)
		|| mlx_is_key_down(game->window, MLX_KEY_LEFT))
		game->p_angle_rad += TURN_ANGLE;
	handle_movement_keys(game, &pos_change);
	game->px += pos_change.x;
	game->py += pos_change.y;
}
