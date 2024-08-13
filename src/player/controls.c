/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:43:24 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/13 17:44:22 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handler_keyboard(mlx_key_data_t key, void *param)
{
	t_game	*game;

	printf("handling keypress...\n");
	game = (t_game *) param;
	if (key.key == MLX_KEY_ESCAPE)
	{
		mlx_delete_image(game->window, game->img);
		mlx_close_window(game->window);
		mlx_terminate(game->window);
		exit(EXIT_SUCCESS);
	}
	else if (key.key == MLX_KEY_RIGHT)
	{
		game->p_angle += TURN_ANGLE;
	}
	else if (key.key == MLX_KEY_LEFT)
	{
		game->p_angle -= TURN_ANGLE;
	}
	else if (key.key == MLX_KEY_UP)
	{
		game->px += sin(game->p_angle) * WALK_SPEED;
		game->py += cos(game->p_angle) * WALK_SPEED;	
	}
	else if (key.key == MLX_KEY_DOWN)
	{
		game->px -= sin(game->p_angle) * WALK_SPEED;
		game->py -= cos(game->p_angle) * WALK_SPEED;
	}
	draw(game);
}
