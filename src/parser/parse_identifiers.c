/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:49:05 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/14 17:47:25 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	all_identifiers_exist(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!game->identifiers[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// Return if identifier is already set before
static int	identifier_already_exists(t_game *game, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0 && game->identifiers[0] == true)
		return (1);
	else if (ft_strncmp(line, "SO ", 3) == 0 && game->identifiers[1] == true)
		return (1);
	else if (ft_strncmp(line, "WE ", 3) == 0 && game->identifiers[2] == true)
		return (1);
	else if (ft_strncmp(line, "EA ", 3) == 0 && game->identifiers[3] == true)
		return (1);
	else if (ft_strncmp(line, "F ", 2) == 0 && game->identifiers[4] == true)
		return (1);
	else if (ft_strncmp(line, "C ", 2) == 0 && game->identifiers[5] == true)
		return (1);
	return (0);
}

static void	mark_identifier(t_game *game, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		game->identifiers[0] = true;
	else if (ft_strncmp(line, "SO ", 3) == 0)
		game->identifiers[1] = true;
	else if (ft_strncmp(line, "WE ", 3) == 0)
		game->identifiers[2] = true;
	else if (ft_strncmp(line, "EA ", 3) == 0)
		game->identifiers[3] = true;
	else if (ft_strncmp(line, "F ", 2) == 0)
		game->identifiers[4] = true;
	else if (ft_strncmp(line, "C ", 2) == 0)
		game->identifiers[5] = true;
}

void	process_line(t_game *game, char *line, int *map_flag)
{
	if (identifier_already_exists(game, line))
		exit_error_parser(game, game->map, ERR_MSG_MULTIPLE_IDENTIFIERS);
	mark_identifier(game, line);
	if (ft_strncmp(line, "NO ", 3) == 0)
		assign_textures(game, &(game->tex_no), line);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		assign_textures(game, &(game->tex_so), line);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		assign_textures(game, &(game->tex_we), line);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		assign_textures(game, &(game->tex_ea), line);
	else if (ft_strncmp(line, "F ", 2) == 0)
		parse_rgb(game, line, &(game->color_floor));
	else if (ft_strncmp(line, "C ", 2) == 0)
		parse_rgb(game, line, &(game->color_ceiling));
	else
	{
		*map_flag = 1;
		add_line_to_map(game, line);
	}
	if (!game->tex_door)
		game->tex_door = load_image(DOOR_TEX_PATH, game, line);
}
