/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:25:58 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/20 19:07:56 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Must be numeric, may have spaces in either side.
// If `require_newline` is true, it must have a single newline at the end.
static int	is_valid_channel_str(char *s, int require_newline)
{
	size_t	s_len;
	size_t	i;
	char	*trimmed;

	if (require_newline)
	{
		s_len = ft_strlen(s);
		if (s_len > 0 && s[s_len - 1] != '\n')
			return (printf("%s\n", ERR_MSG_COLOR_EXPECTS_MORE_LINES), 0);
		s[s_len - 1] = '\0';
	}
	trimmed = ft_strtrim(s, " ");
	if (ft_strlen(trimmed) == 0)
		return (free(trimmed), printf("%s\n", ERR_MSG_EMPTY_COLOR), 0);
	i = 0;
	while (trimmed[i] != '\0')
	{
		if (!ft_isdigit(trimmed[i]))
			return (free(trimmed), printf("%s\n", ERR_MSG_INV_CHAR_IN_COLR), 0);
		++i;
	}
	free(trimmed);
	return (1);
}

// Set the value in `val` into `channel` and return 0.
// Upon error, print error message and return -1.
static int	set_color_channel(\
char *val, unsigned int *channel, int require_newline)
{
	int		channel_val;

	if (!is_valid_channel_str(val, require_newline))
		return (-1);
	channel_val = ft_atoi(val);
	if (channel_val < 0 || channel_val > 255)
	{
		printf("%s\n", ERR_MSG_INVALID_COLORS);
		return (-1);
	}
	*channel = (unsigned int) channel_val;
	return (0);
}

// Handles errors occured in the scope of this file, freeing respective allocs
static void	error_handler(t_game *g, char *msg, char **channels, char *line)
{
	free(line - 2);
	if (channels)
		free_2d_array(channels, find_splits_length(channels));
	exit_error_parser(g, msg);
}

// Skips the inital identifier characters such as "F " part in the map file line
static void	skip_to_rgb_str(char **p_line)
{
	// TODO: if file ends here, line is now \0, what will happen in ft_split_e?
	*p_line += 2;
}

// Parses a comma separated rgb triplet read from `line` into `color`.
// `line` must only consist digits, commas,
// and at most 1 newline character that is at the end of it.
void	parse_rgb(t_game *game, char *line, t_rgba *color)
{
	char	**channels;

	skip_to_rgb_str(&line);
	channels = ft_split_e(line, ',');
	if (channels == NULL)
	{
		error_handler(game, ERR_MSG_ALLOC, channels, line);
	}
	if (find_splits_length(channels) != 3)
	{
		error_handler(game, ERR_MSG_COLOR_INVALID_NUM_CHNLS, channels, line);
	}
	if (set_color_channel(channels[0], &color->r, 0)
		|| set_color_channel(channels[1], &color->g, 0)
		|| set_color_channel(channels[2], &color->b, 1))
	{
		error_handler(game, NULL, channels, line);
	}
	color->a = 255;
	free_2d_array(channels, 3);
}
