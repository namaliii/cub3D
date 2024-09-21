/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:17:25 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/21 10:38:50 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	create_sprite_filename(char *filename, int frame_number)
{
	ft_strlcpy(filename, SPRITE_BASE_PATH, SPRITE_FILE_PATH_LEN);
	ft_strlcat(filename, ft_itoa(frame_number), SPRITE_FILE_PATH_LEN);
	ft_strlcat(filename, ".png", SPRITE_FILE_PATH_LEN);
}

static void	init_sprite(t_game *game)
{
	char	filename[50];
	int		i;

	i = 0;
	while (i < SPRITE_FRAMES)
	{
		create_sprite_filename(filename, i + 1);
		game->sprite.frames[i] = load_image(
				filename, game, NULL, IMG_LOADING_STAGE_INIT);
		i++;
	}
	game->sprite.current_frame = 0;
	game->sprite.direction = 1;
	game->sprite.time_accumulator_sec = 0.0;
}

void	load_textures(t_game *game)
{
	game->tex_door = load_image(
			DOOR_TEX_PATH, game, NULL, IMG_LOADING_STAGE_INIT);
	init_sprite(game);
}

void	init_game(t_game *game)
{
	game->scr_width = SCREEN_WIDTH;
	game->scr_height = SCREEN_HEIGHT;
	game->fov_rad = deg2rad(FOV);
	game->fps_str = safe_calloc(FPS_STR_SIZE, sizeof(char));
	game->window = mlx_init(game->scr_width, game->scr_height, "cub3d", false);
	if (game->window == NULL)
		exit_error(mlx_strerror(mlx_errno));
	game->img = mlx_new_image(game->window, game->scr_width, game->scr_height);
	if (game->img == NULL)
		exit_error_mlx(game, mlx_strerror(mlx_errno));
	if (mlx_image_to_window(game->window, game->img, 0, 0) == -1)
		exit_error_mlx(game, mlx_strerror(mlx_errno));
	game->last_time_sec = mlx_get_time();
}