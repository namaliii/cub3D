/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:39:58 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/14 19:42:57 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_frame(t_game *game)
{
	mlx_delete_image(game->window, game->img);
	game->img = mlx_new_image(game->window, game->scr_width, game->scr_height);
	mlx_image_to_window(game->window, game->img, 0, 0);
	raycast(game);
	draw_minimap(game);
}
