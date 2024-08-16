/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:37:38 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/16 19:14:26 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	normalize_vec2d(t_vec2d *v)
{
	const float	magnitude = sqrtf(v->x * v->x + v->y * v->y);
	const float	inv_sqrt = 1.0 / magnitude;

	if (magnitude > 0)
	{
		v->x = v->x * inv_sqrt;
		v->y = v->y * inv_sqrt;
	}
}

int	min2(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max2(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
