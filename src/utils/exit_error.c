/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:20:17 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/21 13:59:23 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error(const char *msg)
{
	if (msg != NULL)
		printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

void	exit_error_parser(t_game *game, const char *msg)
{
	cleanup_parser(game);
	exit_error(msg);
}

void	exit_error_cleanup_textures(t_game *game, const char *msg)
{
	cleanup_textures(game);
	exit_error_parser(game, msg);
}

void	exit_error_mlx(t_game *game, const char *msg)
{
	cleanup_mlx(game);
	exit_error_cleanup_textures(game, msg);
}
