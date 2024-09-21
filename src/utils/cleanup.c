/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:53:07 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/21 14:02:18 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cleanup_parser(t_game *game)
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
}

void	cleanup_textures(t_game *game)
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
}

void	cleanup_mlx(t_game *game)
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
}

void	total_cleanup(t_game *game)
{
	cleanup_mlx(game);
	cleanup_textures(game);
	cleanup_parser(game);
}
