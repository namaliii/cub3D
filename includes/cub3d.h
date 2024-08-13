/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:52 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/13 22:38:08 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "MLX42.h"

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600

# define MOCK_MAP_HEIGHT 10
# define MOCK_MAP_WIDTH 10

# define ERR_MSG_ALLOC "Error: Allocation failed."

# define PI 3.141592
# define FOV 60
# define TURN_ANGLE 0.1
# define WALK_SPEED 0.16

typedef struct s_rgba
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	a;
}	t_rgba;

typedef struct s_vec2d
{
	float	x;
	float	y;
}	t_vec2d;

typedef struct s_game
{
	// Map
	int		map_width;
	int		map_height;
	char	**map;
	t_rgba	color_floor;
	t_rgba	color_ceiling;
	char	*tex_no_path;
	char	*tex_so_path;
	char	*tex_we_path;
	char	*tex_ea_path;

	// Player
	float	px;
	float	py;
	float	p_angle;
	bool	game_over;

	// Screen
	mlx_t		*window;
	mlx_image_t	*img;
	int			scr_width;
	int			scr_height;
	float		fov;
}	t_game;

// Graphics
void		raycast(t_game *game);
void		draw_minimap(t_game *game);

// Map
bool		is_out_of_bounds(t_game *game, int x, int y);
bool		is_wall(t_game *game, int x, int y);

// Parser
void		parse(int argc, char *argv[], t_game *game);
void		mock_parse(int argc, char *argv[], t_game *game);
void		init_map(t_game *game);

// Player
void		init_player(t_game *game);
void		handler_keyboard(mlx_key_data_t key, void *param);

// Utils
uint32_t	rgba2color(t_rgba rgba);
void		exit_error(const char *msg);
void		*safe_calloc(size_t elems_count, size_t elem_size);
void		debug_print(t_game *game);
void		print_map(t_game *game);

#endif