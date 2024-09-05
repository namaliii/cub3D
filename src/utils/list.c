/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:00:42 by anamieta          #+#    #+#             */
/*   Updated: 2024/08/20 13:17:16 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_2d_array(char **array, int size)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (i < size && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
