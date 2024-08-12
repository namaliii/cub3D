/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:52 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/12 15:40:59 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"
# include "MLX42.h"

#define MOCK_MAP_HEIGHT 10
#define MOCK_MAP_WIDTH 10

typedef struct s_color
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	a;
}	t_color;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	t_color	color_floor;
	t_color	color_ceiling;
	char	*tex_NO_path;
	char	*tex_SO_path;
	char	*tex_WE_path;
	char	*tex_EA_path;
}	t_map;

typedef struct s_player
{
	float	posx;
	float	posy;
	float	angle;
}	t_player;

typedef struct s_vec2d
{
	float	x;
	float	y;
}	t_vec2d;

// Parser
t_map	*parse(int argc, char *argv[]);

// Player
float	player_get_spawn_angle(t_map *map);
t_vec2d	player_get_spawn_coords(t_map *map);

// Utils
void	exit_error();
void	*safe_calloc(size_t elems_count, size_t elem_size);

#endif