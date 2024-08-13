/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:25 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/13 16:58:38 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map(t_game *game)
{
	(void)game;
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
	// parse_map
	init_player(game);
}
