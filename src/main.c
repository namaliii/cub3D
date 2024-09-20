/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:28 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/20 11:27:22 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	compilation_checks(void)
{
	if (WALK_SPEED >= 1.0)
		exit_error(ERR_MSG_INVALID_WALK_SPEED);
	if (COLLISION_DIST_MULTIPLIER < 1.0)
		exit_error(ERR_MSG_INVALID_COL_DIST_TOO_SMALL);
	if (COLLISION_DIST_MULTIPLIER * WALK_SPEED >= 1.0)
		exit_error(ERR_MSG_INVALID_COL_DIST_WALK_SPEED);
	if (!is_tile_solid(TILE_OUT_OF_BOUNDS))
		exit_error(ERR_MSG_INVALID_OUT_OF_BOUNDS_TILE);
}

static void	game_loop(void *param)
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
		exit_error(mlx_strerror(mlx_errno));
	game->img = mlx_new_image(game->window, game->scr_width, game->scr_height);
	if (game->img == NULL)
		exit_error_mlx(game, mlx_strerror(mlx_errno));
	if (mlx_image_to_window(game->window, game->img, 0, 0) == -1)
		exit_error_mlx(game, mlx_strerror(mlx_errno));
	if (game->tex_door == NULL)
		game->tex_door = load_image(DOOR_TEX_PATH, game, NULL);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	compilation_checks();
	if (parse(argc, argv, &game) == 1)
		return (EXIT_FAILURE);
	init(&game);
	mlx_set_cursor_mode(game.window, MLX_MOUSE_HIDDEN);
	mlx_cursor_hook(game.window, &mouse_move_hook, &game);
	mlx_key_hook(game.window, &keyboard_hook, &game);
	mlx_loop_hook(game.window, game_loop, &game);
	mlx_set_mouse_pos(game.window, game.scr_width / 2, game.scr_height / 2);
	mlx_loop(game.window);
	return (0);
}
