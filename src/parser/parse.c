/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:25 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/13 17:30:57 by anamieta         ###   ########.fr       */
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
	texture_path = ft_calloc(i - start + 1, sizeof(char));
	if (texture_path == NULL)
	{
		free(line);
		exit_error(ERR_MSG_ALLOC);
	}
	ft_strlcpy(texture_path, line + start, i - start + 1);
	*tex_img = load_image(texture_path, game, line);
	free(texture_path);
}

int	parse(int argc, char **argv, t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	if (argc != 2)
	{
		printf("%s\n", ERR_MSG_INVALID_ARGC);
		print_usage(argc, argv);
		return (1);
	}
	if (valid_extension(argv[1]) == 1)
		return (1);
	game->game_over = false;
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
