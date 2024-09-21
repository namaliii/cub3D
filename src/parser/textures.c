/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:37:49 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/21 19:51:53 by tunsal           ###   ########.fr       */
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
		exit_error_parser(game, ERR_MSG_ALLOC);
	}
	ft_strlcpy(texture_path, line + start, i - start + 1);
	*tex_img = mlx_load_png(texture_path);
	if (*tex_img == NULL)
	{
		printf("%s\n", texture_path);
		if (line != NULL)
			free(line);
		exit_error_parser(game, ERR_MSG_LOADING_TEXTURE);
	}
	free(texture_path);
}
