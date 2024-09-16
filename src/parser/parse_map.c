/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:56:33 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/16 18:27:56 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_line_to_map(t_game *game, char *line)
{
	char	**new_map;

	if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	new_map = ft_realloc(game->map, sizeof(char *) * game->map_height,
			sizeof(char *) * (game->map_height + 1));
	if (!new_map)
	{
		free(line);
		exit_error_parser(game, game->map, ERR_MSG_FAILED_TO_REALLOC_MAP);
	}
	new_map[game->map_height] = ft_strdup(line);
	if (!new_map[game->map_height])
	{
		free(line);
		free_2d_array(new_map, game->map_height);
		exit_error_parser(game, new_map, ERR_MSG_FAILED_TO_DUP_LINE);
	}
	game->map = new_map;
	game->map_height++;
}

int	get_map_width(t_game *game)
{
	int	max_width;
	int	current_width;
	int	i;

	i = 0;
	max_width = 0;
	while (i < game->map_height)
	{
		if (game->map[i] != NULL)
		{
			current_width = ft_strlen(game->map[i]);
			if (current_width > max_width)
				max_width = current_width;
		}
		i++;
	}
	return (max_width);
}

void	add_padding(t_game *game)
{
	int		i;
	char	*space_line;
	int		line_length;

	space_line = (char *)safe_calloc(game->map_width + 1, sizeof(char));
	i = 0;
	while (i < game->map_height)
	{
		line_length = (int)ft_strlen(game->map[i]);
		if (line_length < game->map_width)
		{
			ft_memset(space_line, ' ', game->map_width);
			ft_memcpy(space_line, game->map[i], line_length);
			free(game->map[i]);
			game->map[i] = (char *)safe_calloc(game->map_width + 1,
					sizeof(char));
			ft_strlcpy(game->map[i], space_line, game->map_width + 1);
		}
		i++;
	}
	free(space_line);
}
