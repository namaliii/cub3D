/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:31:17 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/17 00:33:45 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_map_characters(t_game *game)
{
	char	*valid_chars;
	int		i;
	int		j;

	valid_chars = "NSEW01Dd ";
	i = 0;
	j = 0;
	while (i < game->map_height && game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!ft_strchr(valid_chars, game->map[i][j]))
				exit_error_parser(game, game->map, ERR_MSG_MAP_INVALID_CHARS);
			j++;
		}
		i++;
	}
}

void	top_bottom_check(t_game *game, int *i)
{
	int	j;
	int	curr_line_width;

	if (game->map[*i])
	{
		curr_line_width = ft_strlen(game->map[*i]);
		j = 0;
		while (j < curr_line_width)
		{
			if (game->map[*i][j] != '1' && !ft_isspace(game->map[*i][j]))
				exit_error_parser(game, game->map, ERR_MSG_MAP_NOT_ENCLOSED);
			j++;
		}
	}
}

void	interior_check(t_game *game, int *i)
{
	unsigned long	j;
	unsigned long	width;

	width = ft_strlen(game->map[*i]);
	if (game->map[*i])
	{
		j = 0;
		while (j < width)
		{
			if (ft_strchr("NSEW0Dd", game->map[*i][j]))
			{
				if (ft_isspace(game->map[*i - 1][j])
					|| ft_isspace(game->map[*i + 1][j])
					|| (j > 0 && ft_isspace(game->map[*i][j - 1]))
					|| (j < width - 1
					&& ft_isspace(game->map[*i][j + 1])))
				{
					exit_error_parser(game, game->map,
						ERR_MSG_MAP_NOT_ENCLOSED);
				}
			}
			j++;
		}
	}
}

void	first_last_column(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height && game->map[i])
	{
		j = 0;
		while (ft_isspace(game->map[i][j]))
			j++;
		if (game->map[i][j] != '1')
			exit_error_parser(game, game->map, ERR_MSG_MAP_INVALID);
		i++;
	}
	i = 0;
	while (i < game->map_height && game->map[i])
	{
		j = ft_strlen(game->map[i]);
		while (!game->map[i][j] || (j > 0 && ft_isspace(game->map[i][j])))
			j--;
		if (j >= 0 && game->map[i][j] != '1' && game->map[i][j] != '\0')
			exit_error_parser(game, game->map, ERR_MSG_MAP_NOT_ENCLOSED);
		i++;
	}
}

void	surrounded_by_walls(t_game *game)
{
	int	i;

	i = 0;
	// TODO: is this the place that it segfaults when map.cub doesnt have the map section?
	// If so, it's much more rebust to move this check right after we have done file parsing in parse()
	// It will prevent segfaults in future refactoring
	if (!game->map)
		exit_error(ERR_MSG_MAP_INVALID);
	top_bottom_check(game, &i);
	i = game->map_height - 1;
	top_bottom_check(game, &i);
	i = 1;
	while (i < game->map_height)
	{
		interior_check(game, &i);
		i++;
	}
	first_last_column(game);
}
