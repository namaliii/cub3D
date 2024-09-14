/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:25 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/13 19:44:13 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	open_file(t_game *game, char *file_name)
{
	int	file;

	file = open(file_name, O_RDONLY);
	if (file < 0)
		exit_error_parser(game, game->map, ERR_MSG_FAILED_OPENING_FILE);
	return (file);
}

int	parse(int argc, char **argv, t_game *game)
{
	int	map_fd;

	ft_bzero(game, sizeof(t_game));
	if (argc != 2)
	{
		printf("%s\n", ERR_MSG_INVALID_ARGC);
		print_usage(argc, argv);
		return (1);
	}
	if (!is_valid_extension(argv[1]))
		return (1);
	map_fd = open_file(game, argv[1]);
	parse_file(game, map_fd);
	close(map_fd);
	game->map_width = get_map_width(game);
	add_padding(game);
	if (game->map_width > MAX_MAP_WIDTH || game->map_height > MAX_MAP_HEIGHT)
		exit_error_parser(game, game->map, ERR_MSG_INVALID_MAP_SIZE);
	valid_characters(game);
	surrounded_by_walls(game);
	valid_path(game);
	init_player(game);
	return (0);
}
