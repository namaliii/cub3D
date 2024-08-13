/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:25 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/13 16:04:38 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_mock_map(t_game *game)
{
	int	i;

	game->map_height = MOCK_MAP_HEIGHT;
	game->map = (char **) safe_calloc(game->map_height, sizeof(char *));	
	game->map_width = MOCK_MAP_WIDTH;
	i = 0;
	while (i < MOCK_MAP_HEIGHT)
	{
		game->map[i] = (char *) safe_calloc(game->map_width, sizeof(char));
		++i;
	}
	game->color_floor = (t_rgba) {255, 127, 0, 255};
	game->color_ceiling = (t_rgba) {50, 10, 10, 255};
	game->tex_no_path = NULL;
	game->tex_so_path = NULL;
	game->tex_we_path = NULL;
	game->tex_ea_path = NULL;
	
	char m1[MOCK_MAP_HEIGHT][MOCK_MAP_WIDTH] = {
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '1', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '1', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '1', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
	};

	for (int y = 0; y < MOCK_MAP_HEIGHT; ++y) {
		for (int x = 0; x < MOCK_MAP_WIDTH; ++x) {
			game->map[y][x] = m1[y][x];
		}
	}
}

void	init_map(t_game *game)
{
	game->map_height = 0;
	game->map_width = 0;
	game->map = NULL;
	game->color_floor = (t_rgba) {255, 127, 0, 255};
	game->color_ceiling = (t_rgba) {50, 10, 10, 255};
	game->tex_no_path = NULL;
	game->tex_so_path = NULL;
	game->tex_we_path = NULL;
	game->tex_ea_path = NULL;
}

void	parse(int argc, char *argv[], t_game *game)
{
	(void)argc;
	(void)argv;
	init_map(game);
	set_mock_map(game);
}
