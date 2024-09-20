/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba2color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:16:41 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/20 08:33:19 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	rgba2color(t_rgba rgba)
{
	return (rgba.r << 24 | rgba.g << 16 | rgba.b << 8 | rgba.a);
}

uint32_t	get_mlx_texture_pixel(mlx_texture_t *tex, int x, int y)
{
	return (tex->pixels[(y * tex->width + x) * 4] << 24)
		| (tex->pixels[(y * tex->width + x) * 4 + 1] << 16)
		| (tex->pixels[(y * tex->width + x) * 4 + 2] << 8)
		| (tex->pixels[(y * tex->width + x) * 4 + 3]);
}
