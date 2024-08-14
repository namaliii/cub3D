/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:00:42 by anamieta          #+#    #+#             */
/*   Updated: 2024/08/14 19:06:16 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_2d_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	error_handling(t_game *game, char **array, char *str)
{
	if (game->window)
	{
		mlx_terminate(game->window);
		mlx_close_window(game->window);
	}
	printf("%s", str);
	free_2d_array(array);
	exit(EXIT_FAILURE);
}
