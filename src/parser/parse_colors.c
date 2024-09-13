/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:25:58 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/13 15:16:51 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_channel_str(char *s)
{
	size_t	i;
	char	*trimmed;

	trimmed = ft_strtrim(s, " ");
	i = 0;
	while (trimmed[i] != '\0')
	{
		if (!ft_isdigit(trimmed[i]))
			return (0);
		++i;
	}
	free(trimmed);
	return (1);
}

// Set the value in `val` into `channel` and return 0
// Upon error, print error message and return -1
static int	check_and_set_color_channel(char *val, unsigned int *channel)
{
	int		channel_val;

	if (!is_valid_channel_str(val))
	{
		printf("%s\n", ERR_MSG_INVALID_CHAR_IN_COLOR);
		return (-1);
	}
	channel_val = ft_atoi(val);
	if (channel_val < 0 || channel_val > 255)
	{
		printf("%s\n", ERR_MSG_INVALID_COLORS);
		return (-1);
	}
	*channel = (unsigned int) channel_val;
	return (0);
}

// Return `line` with its newline character discarded at the end
// Return NULL if allocation fails
static char	*discard_if_newline(char *line)
{
	char	*line_without_newline;
	int		line_len;

	line_without_newline = NULL;
	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
	{
		line_without_newline = ft_substr(line, 0, line_len - 1);
	}
	else
	{
		line_without_newline = ft_substr(line, 0, line_len);
	}
	return (line_without_newline);
}

// frees line
// frees color_strs if they exist
// calls the general exit error function
static void	error_handler(\
t_game *game, char *msg, char **color_strs, char *line)
{
	free(line - 2);
	if (color_strs)
		free_2d_array(color_strs, find_splits_length(color_strs));
	exit_error_parser(game, game->map, msg);
}

// Parses a comma separated rgb triplet read from `line` into `color`
// `line` must only consist digits, commas, and newline character
//
// Begins by skipping "F " part in them map file
void	parse_rgb(t_game *game, char *line, t_rgba *color)
{
	char	**color_strs;
	char	*line_without_newline;

	line += 2;
	color_strs = NULL;
	line_without_newline = discard_if_newline(line);
	if (line_without_newline == NULL)
		error_handler(game, ERR_MSG_ALLOC, color_strs, line);
	color_strs = ft_split_e(line_without_newline, ',');
	free(line_without_newline);
	if (color_strs == NULL)
		error_handler(game, ERR_MSG_ALLOC, color_strs, line);
	if (find_splits_length(color_strs) != 3)
		error_handler(game, ERR_MSG_COLOR_INVALID_NUM_CHNLS, color_strs, line);
	if (check_and_set_color_channel(color_strs[0], &color->r)
		|| check_and_set_color_channel(color_strs[1], &color->g)
		|| check_and_set_color_channel(color_strs[2], &color->b))
		error_handler(game, ERR_MSG_COLOR_INVALID_NUM_CHNLS, color_strs, line);
	color->a = 255;
	free_2d_array(color_strs, find_splits_length(color_strs));
}
