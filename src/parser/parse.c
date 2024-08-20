/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:25 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/20 15:24:03 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	assign_color(char *line, t_rgba *color)
{
	char	*ptr;

	ptr = line + 2;
	color->r = (unsigned int)ft_atoi(ptr);
	while (*ptr && *ptr != ',')
		ptr++;
	if (*ptr == ',')
		ptr++;
	color->g = (unsigned int)ft_atoi(ptr);
	while (*ptr && *ptr != ',')
		ptr++;
	if (*ptr == ',')
		ptr++;
	color->b = (unsigned int)ft_atoi(ptr);
	color->a = 255;
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
	game->map_height = 0;
	game->map = NULL;
	open_read_file(game, argv[1]);
	game->map_width = get_map_width(game);
	valid_characters(game);
	surrounded_by_walls(game);
	valid_path(game);
	init_player(game);
	debug_parse(game);
	return (0);
}
