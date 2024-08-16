/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:33:32 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/16 16:39:26 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_assign(t_game *game, int *player, int i, int j)
{
	char	*valid_chars;

	valid_chars = "NSEW";
	if (ft_strchr(valid_chars, game->map[i][j]))
	{
		game->px = (float)j + 0.5;
		game->py = (float)i + 0.5;
		if (game->map[i][j] == 'N')
			game->p_angle = deg2rad(180);
		else if (game->map[i][j] == 'W')
			game->p_angle = deg2rad(90);
		else if (game->map[i][j] == 'S')
			game->p_angle = deg2rad(0);
		else if (game->map[i][j] == 'E')
			game->p_angle = deg2rad(270);
		(*player)++;
	}
}

void	player_check(t_game *game)
{
	int		player;
	int		i;
	int		j;

	player = 0;
	i = 0;
	j = 0;
	while (i < game->map_height && game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			player_assign(game, &player, i, j);
			if (player > 1)
				error_handling(game, game->map,
					"There's more than one player chars");
			j++;
		}
		i++;
	}
	if (player == 0)
		error_handling(game, game->map, "There's no player char");
}

void	init_player(t_game *game)
{
	player_check(game);
	game->game_over = false;
}
