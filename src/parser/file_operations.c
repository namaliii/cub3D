/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:54:22 by anamieta          #+#    #+#             */
/*   Updated: 2024/08/20 13:33:44 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	file_opening(t_game *game, char *file_name)
{
	int	file;

	file = open(file_name, O_RDONLY);
	if (file < 0)
		error_handling(game, game->map, "Failed to open the file");
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
		assign_textures(&(game->tex_no_path), line);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		assign_textures(&(game->tex_so_path), line);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		assign_textures(&(game->tex_we_path), line);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		assign_textures(&(game->tex_ea_path), line);
	else if (ft_strncmp(line, "F ", 2) == 0)
		assign_color(line, &(game->color_floor));
	else if (ft_strncmp(line, "C ", 2) == 0)
		assign_color(line, &(game->color_ceiling));
	else
	{
		*map_flag = 1;
		add_line_to_map(game, line);
	}
}

void	open_read_file(t_game *game, char *file_name)
{
	char	*line;
	int		file;
	int		map_flag;

	map_flag = 0;
	file = file_opening(game, file_name);
	line = get_next_line(file);
	if (!line)
	{
		printf("%s", "The file is empty!\n");
		close(file);
		return ;
	}
	while (line)
	{
		if (line_is_empty(line) && map_flag == 0)
		{
			free(line);
			line = get_next_line(file);
		}
		process_line(game, line, &map_flag);
		free(line);
		line = get_next_line(file);
	}
	close(file);
}
