/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg2rad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:39:09 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/14 17:40:32 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	deg2rad(float angle_degree)
{
	return (angle_degree * (PI / (float) 180));
}
