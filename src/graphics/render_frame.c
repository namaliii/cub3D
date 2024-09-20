/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:39:58 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/20 15:59:06 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_frame(t_game *game)
{
	mlx_delete_image(game->window, game->img);
	game->img = mlx_new_image(game->window, game->scr_width, game->scr_height);
	if (mlx_image_to_window(game->window, game->img, 0, 0) == -1)
		exit_error_mlx(game, mlx_strerror(mlx_errno));
	raycast(game);
	handle_sprite_animation(game);
	draw_minimap(game);
}
