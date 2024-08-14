/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:25 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/14 19:07:35 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map(t_game *game)
{
	(void)game;
}

int	file_opening(t_game *game, char *file_name)
{
	int	file;

	file = open(file_name, O_RDONLY);
	if (file < 0)
	{
		if (game->window)
		{
			mlx_terminate(game->window);
			mlx_close_window(game->window);
		}
		printf("%s\n", "Failed to open the file");
		exit(EXIT_FAILURE);
	}
	return (file);
}

void	assign_textures(char **texture_path, char *line)
{
	int	i;
	int	start;

	i = 3;
	start = i;
	while (line[i] && !ft_isspace(line[i]))
		i++;
	*texture_path = safe_calloc(i - start + 1, sizeof(char));
	ft_strlcpy(*texture_path, line + start, i - start + 1);
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

void	add_line_to_map(t_game *game, char *line)
{
	char	**new_map;
	int		i;

	i = 0;
	if (line_is_empty(line) == 1)
		error_handling(game, game->map, "Empty lines in map\n");
	new_map = (char **)safe_calloc(game->map_height + 1, sizeof(char *));
	while (i < game->map_height)
	{
		new_map[i] = (game->map)[i];
		i++;
	}
	new_map[game->map_height] = ft_strdup(line);
	if (!new_map[game->map_height])
	{
		perror("Failed to duplicate line");
		exit(EXIT_FAILURE);
	}
	if (game->map != NULL)
		free(game->map);
	game->map = new_map;
	game->map_height++;
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
			line = get_next_line(file);
		else if (ft_strncmp(line, "NO ", 3) == 0)
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
			map_flag = 1;
			add_line_to_map(game, line);
		}
		free(line);
		line = get_next_line(file);
	}
	close(file);
}

void	assign_color(char *line, t_rgba *color)
{
	int		r;
	int		g;
	int		b;
	char	*ptr;

	r = -1;
	g = -1;
	b = -1;
	ptr = line + 2;
	r = ft_atoi(ptr);
	while (*ptr && *ptr != ',')
		ptr++;
	if (*ptr == ',')
		ptr++;
	g = ft_atoi(ptr);
	while (*ptr && *ptr != ',')
		ptr++;
	if (*ptr == ',')
		ptr++;
	b = ft_atoi(ptr);
	if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
	{
		color->r = (unsigned int)r;
		color->g = (unsigned int)g;
		color->b = (unsigned int)b;
		color->a = 255;
	}
}

void	init_map(t_game *game, char *file_name)
{
	game->map_height = 0;
	game->map_width = 0;
	game->map = NULL;
	open_read_file(game, file_name);
	//debug
	printf("NO path: %s\n", game->tex_no_path);
	printf("SO path: %s\n", game->tex_so_path);
	printf("WE path: %s\n", game->tex_we_path);
	printf("EA path: %s\n", game->tex_ea_path);
	printf("color ceiling: r:%d, g:%d, b:%d, a:%d\n", game->color_ceiling.r, game->color_ceiling.g, game->color_ceiling.b, game->color_ceiling.a);
	printf("color floor: r:%d, g:%d, b:%d, a:%d\n", game->color_floor.r, game->color_floor.g, game->color_floor.b, game->color_floor.a);
	if (game->map == NULL)
	{
		printf("Map is NULL\n");
		return ;
	}
	for (int i = 0; i < game->map_height; i++)
	{
		if (game->map[i] != NULL)
		{
			printf("%s", game->map[i]);
		}
		else
			printf("Line %d is NULL\n", i);
	}
	printf("%s", "\n");
	printf("Map height: %d\n", game->map_height);
}

int	valid_extension(char *file_name)
{
	int		length;

	length = ft_strlen(file_name) - 1;
	if (file_name[length - 3] != '.' || file_name[length - 2] != 'c'
		|| file_name[length - 1] != 'u' || file_name[length] != 'b')
	{
		printf("%s", "Map extension invalid");
		return (1);
	}
	return (0);
}

int	parse(int argc, char **argv, t_game *game)
{
	if (argc != 2)
	{
		printf("%s", "Wrong number of arguments!\n");
		return (1);
	}
	if (valid_extension(argv[1]) == 1)
		return (1);
	init_map(game, argv[1]);
	// parse_map
	init_player(game);
	return (0);
}
