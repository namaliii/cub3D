/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:25 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/15 18:00:26 by anamieta         ###   ########.fr       */
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
	init_map(game, argv[1]);
	// parse_map
	init_player(game);
	print_debug(game);
	return (0);
}

void	print_debug(t_game *game)
{
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
	printf("Map width: %d\n", game->map_width);
}
