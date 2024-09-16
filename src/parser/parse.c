/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:25 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/17 00:07:07 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parse_line(t_game *game, char **line)
{
	static int	map_flag = 0;
	static bool	empty_line = false;

	if (is_line_empty(*line))
	{
		if (map_flag == 1)
			empty_line = true;
	}
	else
	{
		if (empty_line && map_flag == 1)
		{
			free(*line);
			exit_error_parser(game, game->map, ERR_MSG_MAP_EMPTY_LINE);
		}
		process_line(game, *line, &map_flag);
		empty_line = false;
	}
}

static void	parse_file(t_game *game, int map_fd)
{
	char	*line;

	line = get_next_line(map_fd);
	if (!line)
	{
		printf("%s\n", ERR_MSG_FILE_EMPTY);
		close(map_fd);
		return ;
	}
	while (line != NULL)
	{
		parse_line(game, &line);
		free(line);
		line = get_next_line(map_fd);
	}
	if (!all_identifiers_exist(game))
	{
		free(line);
		close(map_fd);
		exit_error_parser(game, game->map, ERR_MSG_MISSING_IDENTIFIERS);
	}
}

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
