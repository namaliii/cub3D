/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:39:09 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/21 13:35:46 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	deg2rad(float angle_degree)
{
	return (angle_degree * (PI / (float) 180));
}

// Bound the angle `angle_rad` in range [0, 2pi). Angle is assumed to be radians
void	angle_bound(float *angle_rad)
{
	if (*angle_rad < 0)
		*angle_rad += 2 * PI;
	return (fmodf(*angle_rad, 2 * PI));
}

float	angle_subt(float a_rad, float b_rad)
{
	float	result;

	result = a_rad - b_rad;
	angle_bound(&result);
	return (result);
}

float	angle_add(float a_rad, float b_rad)
{
	float	result;

	result = a_rad + b_rad;
	angle_bound(&result);
	return (result);
}
