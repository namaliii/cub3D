/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:28 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/20 18:11:22 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	game_loop(void *param)
{
	double	current_time;
	t_game	*game;

	game = (t_game *)param;
	current_time = mlx_get_time();
	game->delta_time_sec = current_time - game->last_time_sec;
	game->last_time_sec = current_time;
	handle_movement(game);
	render_frame(game);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (parse(argc, argv, &game) == 1)
		return (EXIT_FAILURE);
	load_textures(&game);
	init_game(&game);
	mlx_set_cursor_mode(game.window, MLX_MOUSE_HIDDEN);
	mlx_cursor_hook(game.window, &mouse_move_hook, &game);
	mlx_key_hook(game.window, &keyboard_hook, &game);
	mlx_loop_hook(game.window, game_loop, &game);
	mlx_set_mouse_pos(game.window, game.scr_width / 2, game.scr_height / 2);
	mlx_loop(game.window);
	return (0);
}
