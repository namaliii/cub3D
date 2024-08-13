/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:34:55 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/13 19:44:37 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_player(t_game *game)
{
	printf("px = %f py = %f pa = %f\n", game->px, game->py, game->p_angle);
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
