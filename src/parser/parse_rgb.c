/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:25:58 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/20 12:17:41 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Must be numeric, may have spaces in either side.
// If `allow_newline` is true, it can have a single newline at the end.
static int	is_valid_channel_str(char *s, int allow_newline)
{
	size_t	i;
	char	*trimmed;
	int		nl_count;

	nl_count = 0;
	trimmed = ft_strtrim(s, " ");
	i = 0;
	while (trimmed[i] != '\0')
	{
		if (!ft_isdigit(trimmed[i]) && (allow_newline && trimmed[i] != '\n'))
		{
			free(trimmed);
			return (0);
		}
		if (trimmed[i] == '\n')
			nl_count++;
		++i;
	}
	free(trimmed);
	if (allow_newline && (nl_count > 1 || s[i - 1] != '\n'))
		return (0);
	return (1);
}

// Set the value in `val` into `channel` and return 0.
// Upon error, print error message and return -1.
static int	set_color_channel(\
char *val, unsigned int *channel, int allow_newline)
{
	int		channel_val;

	if (!is_valid_channel_str(val, allow_newline))
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

// Handles errors occured in the scope of this file, freeing respective allocs
static void	error_handler(t_game *g, char *msg, char **channels, char *line)
{
	free(line - 2);
	if (channels)
		free_2d_array(channels, find_splits_length(channels));
	exit_error_parser(g, g->map, msg);
}

// Skips the inital identifier characters such as "F " part in the map file line
static void	skip_to_rgb_str(char **p_line)
{
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
