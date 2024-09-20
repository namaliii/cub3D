/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:02:26 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/20 18:08:20 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_texture_t	*load_image(\
char *path, t_game *game, char *parser_line, int loading_stage)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
	{
		printf("%s\n", path);
		if (loading_stage == IMG_LOADING_STAGE_PARSER)
		{
			if (parser_line != NULL)
				free(parser_line);
			exit_error_parser(game, ERR_MSG_LOADING_TEXTURE);
		}
		if (loading_stage == IMG_LOADING_STAGE_INIT)
			exit_error_cleanup_textures(game, ERR_MSG_LOADING_TEXTURE);
	}
	return (texture);
}
