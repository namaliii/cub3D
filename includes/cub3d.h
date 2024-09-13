/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:52 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/13 10:50:19 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "MLX42.h"
# include "cub3d_err_msg.h"

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600

# define MAX_MAP_WIDTH 270
# define MAX_MAP_HEIGHT 270

# define MOCK_MAP_HEIGHT 10
# define MOCK_MAP_WIDTH 10

# define PI 3.141592
# define FOV 90
# define TURN_ANGLE 0.075
# define WALK_SPEED 0.1

# define SOLID_ELEMENTS "1D"
# define DOOR_CLOSED_CHAR 'D'
# define DOOR_OPENED_CHAR 'd'
# define DIRECTION_OFFSET_COUNT 8

typedef struct s_ray_hit
{
	int		side;
	float	dist;
	int		wall_start_px;
	int		wall_end_px;
	int		wall_height;
}	t_ray_hit;

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
	int				map_width;
	int				map_height;
	char			**map;
	t_rgba			color_floor;
	t_rgba			color_ceiling;
	mlx_texture_t	*tex_no;
	mlx_texture_t	*tex_so;
	mlx_texture_t	*tex_we;
	mlx_texture_t	*tex_ea;
	float			px;
	float			py;
	float			p_angle_rad;
	bool			game_over;
	mlx_t			*window;
	mlx_image_t		*img;
	int				scr_width;
	int				scr_height;
	float			fov_rad;
}	t_game;

// Main
void			game_loop(void *param);

// Graphics
void			render_frame(t_game *game);
void			raycast(t_game *game);
void			draw_minimap(t_game *game);
void			draw_rect(t_game *game, int pos_x, int pos_y,
					int len_x, int len_y, t_rgba color);
void			draw_safe_rect(t_game *game, int pos_x, int pos_y,
					int len_x, int len_y, t_rgba color);
void			draw_textured_wall(t_game *game, int x, float ray_angle,
					t_ray_hit *hit_info);

// Map
bool			is_out_of_bounds(t_game *game, int x, int y);
bool			is_wall(t_game *game, int x, int y);

// Parser
void			assign_color(t_game *game, char *line, t_rgba *color);
void			assign_textures(
					t_game *game, mlx_texture_t **tex_img, char *line);
int				parse(int argc, char **argv, t_game *game);
int				line_is_empty(char *line);
int				file_opening(t_game *game, char *file_name);
void			process_line(t_game *game, char *line, int *map_flag);
void			open_read_file(t_game *game, char *file_name);
void			add_line_to_map(t_game *game, char *line);
mlx_texture_t	*load_image(char *path, t_game *game);
void			add_padding(t_game *game);
int				get_map_width(t_game *game);
void			valid_characters(t_game *game);
void			surrounded_by_walls(t_game *game);
void			valid_path(t_game *game);
void			player_check(t_game *game);

// Player
void			init_player(t_game *game);
void			handle_movement(t_game *game);
void			keyboard_hook(mlx_key_data_t key, void *param);

// Utils
void			exit_error(const char *msg);
void			exit_error_mlx(t_game *game, const char *msg);
void			exit_error_parser(t_game *game, char **map, const char *msg);
void			*safe_calloc(size_t elems_count, size_t elem_size);
void			free_2d_array(char **array, int height);
int				ft_isspace(char c);
int				valid_extension(char *file_name);
int				ft_isnumber(char *str);
void			print_usage(int argc, char **argv);

// Conversions
float			deg2rad(float angle_degree);
uint32_t		rgba2color(t_rgba rgba);

// Debug
void			debug_print(t_game *game);
void			print_map(t_game *game);
void			debug_parse(t_game *game);

// Math
void			normalize_vec2d(t_vec2d *v);
int				min2(int a, int b);
int				max2(int a, int b);

#endif