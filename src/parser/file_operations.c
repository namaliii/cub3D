/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:54:22 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/14 14:06:54 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
