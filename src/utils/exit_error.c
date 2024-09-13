/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:20:17 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/13 16:54:49 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error_parser(t_game *game, char **map, const char *msg)
{
	free_2d_array(map, game->map_height);
	exit_error_mlx(game, msg);
}

void	exit_error_mlx(t_game *game, const char *msg)
{
	if (game->window)
	{
		mlx_close_window(game->window);
		mlx_terminate(game->window);
	}
	exit_error(msg);
}

void	exit_error(const char *msg)
{
	if (msg != NULL)
		printf("%s\n", msg);
	exit(EXIT_FAILURE);
}
