/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:28 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/17 19:03:15 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	handle_movement(game);
	render_frame(game);
}

static void	init(t_game *game)
{
	game->scr_width = SCREEN_WIDTH;
	game->scr_height = SCREEN_HEIGHT;
	game->fov_rad = deg2rad(FOV);
	game->window = mlx_init(game->scr_width, game->scr_height, "cub3d", false);
	if (game->window == NULL)
		exit_error(mlx_strerror(mlx_errno)); // TODO: mlx_close_window()
	game->img = mlx_new_image(game->window, game->scr_width, game->scr_height);
	if (game->img == NULL)
		exit_error(mlx_strerror(mlx_errno)); // TODO: mlx_close_window()
	if (mlx_image_to_window(game->window, game->img, 0, 0) == -1)
		exit_error(mlx_strerror(mlx_errno)); // TODO: mlx_close_window()
}

int	main(int argc, char *argv[])
{
	t_game	game;

	// mock_parse(argc, argv, &game);
	ft_bzero(&game, sizeof(t_game));
	if (parse(argc, argv, &game) == 1)
		return (1);
	init(&game);
	mlx_key_hook(game.window, &keyboard_hook, &game);
	mlx_loop_hook(game.window, game_loop, &game);
	mlx_loop(game.window);
	return (0);
}
