/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:54:22 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/13 11:49:52 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	file_opening(t_game *game, char *file_name)
{
	int	file;

	file = open(file_name, O_RDONLY);
	if (file < 0)
		exit_error_parser(game, game->map, ERR_MSG_FAILED_OPENING_FILE);
	return (file);
}

int	line_is_empty(char *line)
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

void	process_line(t_game *game, char *line, int *map_flag)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		assign_textures(game, &(game->tex_no), line);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		assign_textures(game, &(game->tex_so), line);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		assign_textures(game, &(game->tex_we), line);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		assign_textures(game, &(game->tex_ea), line);
	else if (ft_strncmp(line, "F ", 2) == 0)
		parse_rgb(game, line + 2, &(game->color_floor));
	else if (ft_strncmp(line, "C ", 2) == 0)
		parse_rgb(game, line + 2, &(game->color_ceiling));
	else
	{
		*map_flag = 1;
		add_line_to_map(game, line);
	}
}

void	check_and_process(t_game *game, char **line, int *file)
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
			exit_error_parser(game, game->map, ERR_MSG_MAP_EMPTY_LINE);
		process_line(game, *line, &map_flag);
		empty_line = false;
	}
	free(*line);
	*line = get_next_line(*file);
}

void	open_read_file(t_game *game, char *file_name)
{
	char	*line;
	int		file;

	file = file_opening(game, file_name);
	line = get_next_line(file);
	if (!line)
	{
		printf("%s\n", ERR_MSG_FILE_EMPTY);
		close(file);
		return ;
	}
	while (line)
		check_and_process(game, &line, &file);
	close(file);
}
