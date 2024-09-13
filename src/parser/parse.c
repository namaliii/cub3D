/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:25 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/13 10:50:27 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_textures(t_game *game, mlx_texture_t **tex_img, char *line)
{
	int		i;
	int		start;
	char	*texture_path;

	i = 3;
	start = i;
	while (line[i] && !ft_isspace(line[i]))
		i++;
	texture_path = safe_calloc(i - start + 1, sizeof(char));
	ft_strlcpy(texture_path, line + start, i - start + 1);
	*tex_img = load_image(texture_path, game);
	free(texture_path);
}

void	invalid_chars_check(t_game *game, char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (!ft_isdigit(ptr[i]) && !ft_isspace(ptr[i]) && ptr[i] != ',')
			exit_error_parser(game, game->map, ERR_MSG_INVALID_CHAR_IN_COLOR);
		i++;
	}
}

void	assign_color(t_game *game, char *line, t_rgba *color)
{
	char			*ptr;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	ptr = line + 2;
	invalid_chars_check(game, ptr);
	r = (unsigned int)ft_atoi(ptr);
	while (*ptr && *ptr != ',')
		ptr++;
	if (*ptr == ',')
		ptr++;
	g = (unsigned int)ft_atoi(ptr);
	while (*ptr && *ptr != ',')
		ptr++;
	if (*ptr == ',')
		ptr++;
	b = (unsigned int)ft_atoi(ptr);
	if (r > 255|| g > 255|| b > 255)
		exit_error_parser(game, game->map, ERR_MSG_INVALID_COLORS);
	color->r = r;
	color->g = g;
	color->b = b;
	color->a = 255;
}

int	parse(int argc, char **argv, t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	if (argc != 2)
	{
		printf("%s\n", ERR_MSG_INVALID_ARGC);
		print_usage(argc, argv);
		return (EXIT_FAILURE);
	}
	if (valid_extension(argv[1]) == 1)
		return (EXIT_FAILURE);
	game->map_height = 0;
	game->map = NULL;
	open_read_file(game, argv[1]);
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
