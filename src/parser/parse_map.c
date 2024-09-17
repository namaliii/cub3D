/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:56:33 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/17 17:54:41 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	add_padding_to_map(t_game *game)
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

static void	add_line_to_map(t_game *game, char *line)
{
	if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	game->map = ft_realloc(game->map, sizeof(char *) * game->map_height,
			sizeof(char *) * (game->map_height + 1));
	if (game->map == NULL)
	{
		free(line);
		exit_error_parser(game, game->map, ERR_MSG_FAILED_TO_REALLOC_MAP);
	}
	game->map[game->map_height] = ft_strdup(line);
	if (game->map[game->map_height] == NULL)
	{
		free(line);
		exit_error_parser(game, game->map, ERR_MSG_FAILED_TO_DUP_LINE);
	}
	game->map_height++;
}

void	parse_map_line(t_game *game, char *line)
{
	if (is_line_empty(line))
	{
		free(line);
		exit_error_parser(game, game->map, ERR_MSG_MAP_EMPTY_LINE);
	}
	add_line_to_map(game, line);
}
