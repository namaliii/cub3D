/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_compare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:33:20 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/21 14:33:58 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	min2(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

float	min2f(float a, float b)
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

// If val < min, val = min, if val > max, val = max
void	clamp(int *val, int min, int max)
{
	if (*val < min)
		*val = min;
	else if (*val > max)
		*val = max;
}
