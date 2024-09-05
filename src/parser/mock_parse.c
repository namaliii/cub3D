/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:46:35 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/27 17:51:50 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	mock_parse_map(t_game *game)
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
	game->tex_no = NULL;
	game->tex_so = NULL;
	game->tex_we = NULL;
	game->tex_ea = NULL;

	char m1[MOCK_MAP_HEIGHT][MOCK_MAP_WIDTH] = {
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '1', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '1', '1', 'D', '1'},
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

static void	mock_init_player(t_game *game)
{
	int first_free_x, first_free_y;
	int found_flag = false;

	for (first_free_y = 0; first_free_y < game->map_height; ++first_free_y)
	{
		for (first_free_x = 0; first_free_x < game->map_width; ++first_free_x)
		{
			if (game->map[first_free_y][first_free_x] == '0')
			{
				game->px = first_free_x + 0.5;
				game->py = first_free_y + 0.5;
				found_flag = true;
				break;
			}
		}

		if (found_flag)
			break;
	}

	if (!found_flag)
		exit_error("Couldn't find a valid player spawn position.");

	game->px = 2.5;
	game->py = 2.5;
	game->p_angle_rad = deg2rad(0.0);
	game->game_over = false;
}

static void	mock_init_map(t_game *game)
{
	game->map_height = 0;
	game->map_width = 0;
	game->map = NULL;
	game->color_floor = (t_rgba) {255, 127, 0, 255};
	game->color_ceiling = (t_rgba) {50, 10, 10, 255};
	game->tex_no = NULL;
	game->tex_so = NULL;
	game->tex_we = NULL;
	game->tex_ea = NULL;
}

void	mock_parse(int argc, char *argv[], t_game *game)
{
	(void)argc;
	(void)argv;
	mock_init_map(game);
	mock_parse_map(game);
	mock_init_player(game);
}
