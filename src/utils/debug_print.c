/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:34:55 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/13 15:46:25 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_player(t_game *game)
{
	printf("px = %f py = %f pa = %f\n", game->px, game->py, game->p_angle_rad);
}

void	print_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			printf("%c", game->map[y][x]);
			++x;
		}
		printf("\n");
		++y;
	}
}

void	debug_print(t_game *game)
{
	print_player(game);
}

void	debug_parse(t_game *game)
{
	int	i;

	printf("color ceiling: r:%d, g:%d, b:%d, a:%d\n", game->color_ceiling.r, \
game->color_ceiling.g, game->color_ceiling.b, game->color_ceiling.a);
	printf("color floor: r:%d, g:%d, b:%d, a:%d\n", game->color_floor.r, \
game->color_floor.g, game->color_floor.b, game->color_floor.a);
	if (game->map == NULL)
	{
		printf("Map is NULL\n");
		return ;
	}
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i] != NULL)
			printf("%d: %s", i, game->map[i]);
		else
			printf("Line %d is NULL\n", i);
		printf("%s", "\n");
		++i;
	}
	printf("Map height: %d\n", game->map_height);
	printf("Map width: %d\n", game->map_width);
	printf("Player px: %f, py: %f, p_angle: %f\n", game->px, game->py, \
game->p_angle_rad);
}

void	print_string_arr(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i] != NULL)
	{
		printf("str_arr[%d] = <%s>\n", i, str_arr[i]);
		++i;
	}
}
