/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:37:38 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/13 21:02:31 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vec2d_normalize(t_vec2d *v)
{
	const float	magnitude = sqrtf(v->x * v->x + v->y * v->y);
	const float	inv_sqrt = 1.0 / magnitude;

	if (magnitude > 0)
	{
		v->x = v->x * inv_sqrt;
		v->y = v->y * inv_sqrt;
	}
}

// Update the values of vector `v` multiplying it by `scalar`, and return it too
t_vec2d	*vec2d_mult_by_scalar(t_vec2d *v, float scalar)
{
	v->x *= scalar;
	v->y *= scalar;
	return (v);
}

// Rotate vector `v` counter clockwise direction by `angle`
void	vec2d_rot_ccw(t_vec2d *v, float angle)
{
	float	new_x;
	float	new_y;

	new_x = v->x * cos(angle) - v->y * sin(angle);
	new_y = v->x * sin(angle) - v->y * cos(angle);
	v->x = new_x;
	v->y = new_y;
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
