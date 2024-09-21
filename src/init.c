/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:17:25 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/21 20:00:05 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	create_sprite_filename(t_game *game, char *filename, int frame_num)
{
	char	*frame_number_str;

	frame_number_str = ft_itoa(frame_num);
	if (frame_number_str == NULL)
	{
		printf("%s\n", filename);
		exit_error_cleanup_textures(game, ERR_MSG_LOADING_TEXTURE);
	}
	ft_strlcpy(filename, SPRITE_BASE_PATH, SPRITE_FILE_PATH_LEN);
	ft_strlcat(filename, frame_number_str, SPRITE_FILE_PATH_LEN);
	ft_strlcat(filename, ".png", SPRITE_FILE_PATH_LEN);
	free(frame_number_str);
}

static void	init_sprite(t_game *game)
{
	char	filename[SPRITE_FILE_PATH_LEN];
	int		i;

	i = 0;
	while (i < SPRITE_FRAMES)
	{
		create_sprite_filename(game, filename, i + 1);
		game->sprite.frames[i] = mlx_load_png(filename);
		if (game->sprite.frames[i] == NULL)
		{
			printf("%s\n", filename);
			exit_error_cleanup_textures(game, ERR_MSG_LOADING_TEXTURE);
		}
		i++;
	}
	game->sprite.current_frame = 0;
	game->sprite.direction = 1;
	game->sprite.time_accumulator_sec = 0.0;
}

void	load_textures(t_game *game)
{
	game->tex_door = mlx_load_png(DOOR_TEX_PATH);
	if (game->tex_door == NULL)
	{
		printf("%s\n", DOOR_TEX_PATH);
		exit_error_cleanup_textures(game, ERR_MSG_LOADING_TEXTURE);
	}
	init_sprite(game);
}

void	init_game(t_game *game)
{
	game->scr_width = SCREEN_WIDTH;
	game->scr_height = SCREEN_HEIGHT;
	game->fov_rad = deg2rad(FOV);
	game->fps_str = ft_calloc(FPS_STR_SIZE, sizeof(char));
	if (game->fps_str == NULL)
		exit_error_mlx(game, ERR_MSG_ALLOC);
	game->window = mlx_init(game->scr_width, game->scr_height, "cub3d", false);
	if (game->window == NULL)
		exit_error_mlx(game, mlx_strerror(mlx_errno));
	game->img = mlx_new_image(game->window, game->scr_width, game->scr_height);
	if (game->img == NULL)
		exit_error_mlx(game, mlx_strerror(mlx_errno));
	if (mlx_image_to_window(game->window, game->img, 0, 0) == -1)
		exit_error_mlx(game, mlx_strerror(mlx_errno));
	game->last_time_sec = mlx_get_time();
}
