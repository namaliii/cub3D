/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:28 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/14 17:40:59 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init(t_game *game)
{
	game->scr_width = SCREEN_WIDTH;
	game->scr_height = SCREEN_HEIGHT;
	game->fov = deg2rad(FOV);
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

	mock_parse(argc, argv, &game);
	init(&game);
	mlx_key_hook(game.window, &handler_keyboard, &game);
	raycast(&game);
	draw_minimap(&game);
	mlx_loop(game.window);
}
