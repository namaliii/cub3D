/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:54:22 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/13 19:43:26 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	all_identifiers_exist(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!game->identifiers[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// Return if identifier is already set before
static int	identifier_already_exists(t_game *game, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0 && game->identifiers[0] == true)
		return (1);
	else if (ft_strncmp(line, "SO ", 3) == 0 && game->identifiers[1] == true)
		return (1);
	else if (ft_strncmp(line, "WE ", 3) == 0 && game->identifiers[2] == true)
		return (1);
	else if (ft_strncmp(line, "EA ", 3) == 0 && game->identifiers[3] == true)
		return (1);
	else if (ft_strncmp(line, "F ", 2) == 0 && game->identifiers[4] == true)
		return (1);
	else if (ft_strncmp(line, "C ", 2) == 0 && game->identifiers[5] == true)
		return (1);
	return (0);
}

static void	mark_identifier(t_game *game, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		game->identifiers[0] = true;
	else if (ft_strncmp(line, "SO ", 3) == 0)
		game->identifiers[1] = true;
	else if (ft_strncmp(line, "WE ", 3) == 0)
		game->identifiers[2] = true;
	else if (ft_strncmp(line, "EA ", 3) == 0)
		game->identifiers[3] = true;
	else if (ft_strncmp(line, "F ", 2) == 0)
		game->identifiers[4] = true;
	else if (ft_strncmp(line, "C ", 2) == 0)
		game->identifiers[5] = true;
}

void	process_line(t_game *game, char *line, int *map_flag)
{
	if (identifier_already_exists(game, line))
	{
		; // TODO: error
	}
	mark_identifier(game, line);
	if (ft_strncmp(line, "NO ", 3) == 0)
		assign_textures(game, &(game->tex_no), line);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		assign_textures(game, &(game->tex_so), line);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		assign_textures(game, &(game->tex_we), line);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		assign_textures(game, &(game->tex_ea), line);
	else if (ft_strncmp(line, "F ", 2) == 0)
		parse_rgb(game, line, &(game->color_floor));
	else if (ft_strncmp(line, "C ", 2) == 0)
		parse_rgb(game, line, &(game->color_ceiling));
	else
	{
		*map_flag = 1;
		add_line_to_map(game, line);
	}
}

static int	line_is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_and_process(t_game *game, char **line)
{
	static int	map_flag = 0;
	static bool	empty_line = false;

	if (line_is_empty(*line))
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

void	parse_file(t_game *game, int map_fd)
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
		check_and_process(game, &line);
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
