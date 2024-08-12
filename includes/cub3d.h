/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:52 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/12 18:21:57 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "MLX42.h"

# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480

# define MOCK_MAP_HEIGHT 10
# define MOCK_MAP_WIDTH 10

# define ERR_MSG_ALLOC "Error: Allocation failed."

# define PI 3.141592

typedef struct s_rgba
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	a;
}	t_rgba;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	t_rgba	color_floor;
	t_rgba	color_ceiling;
	char	*tex_no_path;
	char	*tex_so_path;
	char	*tex_we_path;
	char	*tex_ea_path;
}	t_map;

typedef struct s_player
{
	float	posx;
	float	posy;
	float	angle;
	bool	game_over;
}	t_player;

typedef struct s_vec2d
{
	float	x;
	float	y;
}	t_vec2d;

typedef struct s_screen
{
	mlx_t		*window;
	mlx_image_t	*img;
	int			width;
	int			height;
	float		fov;
}	t_screen;

// Graphics
void		raycast(t_screen *screen, t_map *map, t_player *player);

// Map
t_map		*parse(int argc, char *argv[]);
bool		is_out_of_bounds(t_map *map, int x, int y);
bool		is_wall(t_map *map, int x, int y);

// Player
void		init_player(t_player *player, t_map *map);

// Utils
uint32_t	rgba2color(t_rgba rgba);
void		exit_error(const char *msg);
void		*safe_calloc(size_t elems_count, size_t elem_size);

#endif