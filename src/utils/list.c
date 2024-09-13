/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:00:42 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/13 11:42:25 by tunsal           ###   ########.fr       */
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

// Get length of a NULL terminated array of strings
int	find_splits_length(char **splits)
{
	int	i;

	i = 0;
	while (splits[i] != NULL)
		++i;
	return (i);
}
