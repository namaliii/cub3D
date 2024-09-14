/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:37:49 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/14 14:24:20 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_textures(t_game *game, mlx_texture_t **tex_img, char *line)
{
	int		i;
	int		start;
	char	*texture_path;

	i = 3;
	start = i;
	while (line[i] && !ft_isspace(line[i]))
		i++;
	texture_path = ft_calloc(i - start + 1, sizeof(char));
	if (texture_path == NULL)
	{
		free(line);
		exit_error(ERR_MSG_ALLOC);
	}
	ft_strlcpy(texture_path, line + start, i - start + 1);
	*tex_img = load_image(texture_path, game, line);
	free(texture_path);
}

mlx_texture_t	*load_image(char *path, t_game *game, char *line)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
	{
		free(line);
		exit_error_parser(game, game->map, ERR_MSG_LOADING_TEXTURE);
	}
	return (texture);
}
