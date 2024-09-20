/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:25 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/20 19:07:13 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	all_identifiers_exist(t_game *game)
{
	int	i;

	i = 0;
	while (i < IDENTIFIER_COUNT)
	{
		if (!game->identifiers[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static void	parse_line(t_game *game, char **line, int *parsing_state)
{
	if (*parsing_state == PARSING_STATE_IDENTIFIERS)
	{
		parse_identifier_line(game, *line);
		if (all_identifiers_exist(game))
		{
			*parsing_state = PARSING_STATE_WAITING_MAP;
		}
	}
	else if (*parsing_state == PARSING_STATE_WAITING_MAP)
	{
		if (!is_line_empty(*line))
		{
			*parsing_state = PARSING_STATE_MAP;
			parse_map_line(game, *line);
		}
	}
	else
	{
		parse_map_line(game, *line);
	}
}

static void	parse_file(t_game *game, int map_fd)
{
	char	*line;
	int		parsing_state;

	parsing_state = PARSING_STATE_IDENTIFIERS;
	line = get_next_line(map_fd);
	if (!line)
	{
		printf("%s\n", ERR_MSG_FILE_EMPTY);
		close(map_fd);
		return ;
	}
	while (line != NULL)
	{
		parse_line(game, &line, &parsing_state);
		free(line);
		line = get_next_line(map_fd);
	}
}

static int	open_file(t_game *game, char *file_name)
{
	int	file;

	file = open(file_name, O_RDONLY);
	if (file < 0)
		exit_error_parser(game, ERR_MSG_FAILED_OPENING_FILE);
	return (file);
}

int	parse(int argc, char **argv, t_game *game)
{
	int	map_fd;

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
	if (game->map == NULL)
		exit_error(ERR_MSG_MAP_INVALID);
	game->map_width = get_map_width(game);
	add_padding_to_map(game);
	if (game->map_width > MAX_MAP_WIDTH || game->map_height > MAX_MAP_HEIGHT)
		exit_error_parser(game, ERR_MSG_INVALID_MAP_SIZE);
	validate_map_characters(game);
	surrounded_by_walls(game);
	valid_path(game);
	init_player(game);
	return (0);
}
