/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:25:58 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/13 12:34:09 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_and_set_color_channel(\
t_game *game, char *val, unsigned int *channel)
{
	int		channel_val;

	if (!str_is_numeric(val))
	{
		exit_error_parser(game, game->map, ERR_MSG_INVALID_CHAR_IN_COLOR);
	}
	channel_val = ft_atoi(val);
	if (channel_val < 0 || channel_val > 255)
	{
		exit_error_parser(game, game->map, ERR_MSG_INVALID_COLORS);
	}
	*channel = (unsigned int) channel_val;
}

char	*discard_newline(char *line)
{
	char	*line_without_newline;
	int		line_len;

	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
	{
		line_without_newline = ft_substr(line, 0, line_len - 1);
	}
	else
	{
		line_without_newline = ft_substr(line, 0, line_len);
		; // free(line_without_newline), error?, it's not ending with \n, something wrong?
	}
	return (line_without_newline);
}

// Parses a comma separated rgb triplet read from `line` into `color`
// `line` must only consist digits, commas, and newline character
void	parse_rgb(t_game *game, char *line, t_rgba *color)
{
	char	**color_strs;
	char	*line_without_newline;
	
	line_without_newline = discard_newline(line);
	color_strs = ft_split_e(line_without_newline, ',');
	free(line_without_newline);
	if (color_strs == NULL)
	{
		exit_error_parser(game, game->map, ERR_MSG_ALLOC);
	}
	if (find_splits_length(color_strs) != 3)
	{
		exit_error_parser(game, game->map, ERR_MSG_COLOR_INVALID_NUM_CHANNELS);
	}
	check_and_set_color_channel(game, color_strs[0], &color->r);
	check_and_set_color_channel(game, color_strs[1], &color->g);
	check_and_set_color_channel(game, color_strs[2], &color->b);
	color->a = 255;
	print_string_arr(color_strs);
}
