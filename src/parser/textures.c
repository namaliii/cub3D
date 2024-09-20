/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:37:49 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/20 18:09:46 by tunsal           ###   ########.fr       */
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
	*tex_img = load_image(texture_path, game, line, IMG_LOADING_STAGE_PARSER);
	free(texture_path);
}
