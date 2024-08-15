/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:56:33 by anamieta          #+#    #+#             */
/*   Updated: 2024/08/15 18:00:33 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map(t_game *game)
{
	(void)game;
}

void	add_line_to_map(t_game *game, char *line)
{
	char	**new_map;
	int		i;

	i = 0;
	if (line_is_empty(line) == 1)
		error_handling(game, game->map, "Empty line in map!\n");
	new_map = (char **)safe_calloc(game->map_height + 1, sizeof(char *));
	while (i < game->map_height)
	{
		new_map[i] = (game->map)[i];
		i++;
	}
	new_map[game->map_height] = ft_strdup(line);
	if (!new_map[game->map_height])
	{
		perror("Failed to duplicate line");
		exit(EXIT_FAILURE);
	}
	if (game->map != NULL)
		free(game->map);
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
	return (max_width - 1);
}

void	init_map(t_game *game, char *file_name)
{
	game->map_height = 0;
	game->map = NULL;
	open_read_file(game, file_name);
	game->map_width = get_map_width(game);
}
