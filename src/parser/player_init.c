/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:33:32 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/17 19:09:42 by anamieta         ###   ########.fr       */
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
			game->p_angle_rad = deg2rad(180);
		else if (game->map[i][j] == 'W')
			game->p_angle_rad = deg2rad(90);
		else if (game->map[i][j] == 'S')
			game->p_angle_rad = deg2rad(0);
		else if (game->map[i][j] == 'E')
			game->p_angle_rad = deg2rad(270);
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
				exit_error_parser(game, game->map,
					"There's more than one player chars");
			j++;
		}
		i++;
	}
	if (player == 0)
		exit_error_parser(game, game->map, "There's no player char");
}

void	init_player(t_game *game)
{
	player_check(game);
	game->game_over = false;
}

	// int first_free_x, first_free_y;
	// int found_flag = false;

	// for (first_free_y = 0; first_free_y < map->height; ++first_free_y)
	// {
	// 	for (first_free_x = 0; first_free_x < map->width; ++first_free_x)
	// 	{
	// 		if (map->map[first_free_y][first_free_x] == '0')
	// 		{
	// 			player->posx = first_free_x + 0.5;
	// 			player->posy = first_free_y + 0.5;
	// 			found_flag = true;
	// 			break;
	// 		}
	// 	}

	// 	if (found_flag)
	// 		break;
	// }

	// if (!found_flag)
	// 	exit_error("Couldn't find a valid player spawn position.");