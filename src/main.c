/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:28 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/12 18:15:32 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init(t_screen *screen)
{
	screen->width = SCREEN_WIDTH;
	screen->height = SCREEN_HEIGHT;
	screen->window = mlx_init(screen->width, screen->height, "cub3d", false);
	if (screen->window == NULL)
		exit_error(mlx_strerror(mlx_errno)); // TODO: mlx_close_window()
	screen->img = mlx_new_image(screen->window, screen->width, screen->height);
	if (screen->img == NULL)
		exit_error(mlx_strerror(mlx_errno)); // TODO: mlx_close_window()
	if (mlx_image_to_window(screen->window, screen->img, 0, 0) == -1)
		exit_error(mlx_strerror(mlx_errno)); // TODO: mlx_close_window()
}

int	main(int argc, char *argv[])
{
	t_screen	screen;
	t_player	player;
	t_map		*map;

	map = parse(argc, argv);
	init_player(&player, map);
	init(&screen);
	// movement hooks?
	// mlx_scroll_hook();
	// mlx_key_hook();
	while (!player.game_over)
	{
		// clearscreen?
		raycast(&screen, map, &player);
		mlx_image_to_window(screen.window, screen.img, 0, 0);
		// mlx_delete_image();
		// mlx_new_image();
	}
}
