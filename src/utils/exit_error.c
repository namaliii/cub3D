/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:20:17 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/21 10:39:14 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error(const char *msg)
{
	if (msg != NULL)
		printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

void	exit_error_parser(t_game *game, const char *msg)
{
	if (game->tex_no != NULL)
		mlx_delete_texture(game->tex_no);
	if (game->tex_so != NULL)
		mlx_delete_texture(game->tex_so);
	if (game->tex_we != NULL)
		mlx_delete_texture(game->tex_we);
	if (game->tex_ea != NULL)
		mlx_delete_texture(game->tex_ea);
	free_2d_array(game->map, game->map_height);
	exit_error(msg);
}

void	exit_error_cleanup_textures(t_game *game, const char *msg)
{
	int	i;

	if (game->tex_door != NULL)
		mlx_delete_texture(game->tex_door);
	i = 0;
	while (i < SPRITE_FRAMES)
	{
		if (game->sprite.frames[i] != NULL)
			mlx_delete_texture(game->sprite.frames[i]);
		++i;
	}
	exit_error_parser(game, msg);
}

void	exit_error_mlx(t_game *game, const char *msg)
{
	if (game->window)
	{
		if (game->img != NULL)
		{
			mlx_delete_image(game->window, game->img);
			game->img = NULL;
		}
		mlx_close_window(game->window);
		mlx_terminate(game->window);
	}
	if (game->fps_str != NULL)
		free(game->fps_str);
	exit_error_cleanup_textures(game, msg);
}
