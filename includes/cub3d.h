/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:52 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/17 19:15:06 by anamieta         ###   ########.fr       */
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

# define PARSING_STATE_IDENTIFIERS 1000
# define PARSING_STATE_WAITING_MAP 1001
# define PARSING_STATE_MAP 1002

# define PI 3.141592
# define FOV 60
# define TURN_ANGLE 0.075
# define WALK_SPEED 0.1
# define MOUSE_SENSITIVITY 0.001
# define COLLISION_DIST 7

# define SOLID_ELEMENTS "1D"
# define DOOR_CLOSED_CHAR 'D'
# define DOOR_OPENED_CHAR 'd'
# define DOOR_TEX_PATH "./img/door.png"
# define DIRECTION_OFFSET_COUNT 8

# define HIT_NONE 0
# define HIT_VERTICAL_WALL 1
# define HIT_HORIZONTAL_WALL 2
# define HIT_DOOR 3

typedef struct s_ray_hit
{
	int		side;
	float	dist;
	int		ceil_end_px;
	int		floor_start_px;
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

typedef struct s_rect
{
	int		posx;
	int		posy;
	int		lenx;
	int		leny;
	t_rgba	color;
}	t_rect;

typedef struct s_minimap
{
	float			scale_horiz;
	float			scale_vert;
	float			line_len;
	float			line_thick;
	t_rgba			line_color;
}	t_minimap;

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
	mlx_texture_t	*tex_door;
	float			px;
	float			py;
	float			p_angle_rad;
	bool			game_over;
	mlx_t			*window;
	mlx_image_t		*img;
	int				scr_width;
	int				scr_height;
	float			fov_rad;
	bool			identifiers[6];
}	t_game;

typedef struct s_dda_vars
{
	float	ray_dir_x;
	float	ray_dir_y;
	float	delta_dist_x;
	float	delta_dist_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	float	side_dist_x;
	float	side_dist_y;
	int		hit ;
	int		side;
	float	perp_wall_dist;
}	t_dda_vars;

// Graphics
void			render_frame(t_game *game);
void			raycast(t_game *game);
void			find_dist(float angle, t_game *game, t_ray_hit *p_ray_hit);
void			draw_minimap(t_game *game);
void			draw_rect(t_game *game, t_rect r);
void			draw_safe_rect(t_game *game, t_rect r);
void			draw_textured_wall(t_game *game, int x, float ray_angle,
					t_ray_hit *hit_info);

// Map
bool			is_out_of_bounds(t_game *game, int x, int y);
bool			is_wall(t_game *game, int x, int y);

// Parser
int				parse(int argc, char **argv, t_game *game);
void			parse_map_line(t_game *game, char *line);
void			parse_identifier_line(t_game *game, char *line);
void			parse_rgb(t_game *game, char *line, t_rgba *color);
void			assign_textures(
					t_game *game, mlx_texture_t **tex_img, char *line);
mlx_texture_t	*load_image(char *path, t_game *game, char *line);
void			add_padding_to_map(t_game *game);
int				get_map_width(t_game *game);
void			validate_map_characters(t_game *game);
void			surrounded_by_walls(t_game *game);
void			valid_path(t_game *game);
void			init_player(t_game *game);

// Player
void			handle_movement(t_game *game);
void			keyboard_hook(mlx_key_data_t key, void *param);
void			mouse_move_hook(double xpos, double ypos, void *param);

// Utils
void			exit_error(const char *msg);
void			exit_error_mlx(t_game *game, const char *msg);
void			exit_error_parser(t_game *game, char **map, const char *msg);
void			*safe_calloc(size_t elems_count, size_t elem_size);
void			free_2d_array(char **array, int height);
int				find_splits_length(char **splits);
void			print_usage(int argc, char **argv);
void			print_string_arr(char **str_arr);
void			print_vec2d(t_vec2d *v);
char			**ft_split_e(char const *str, char separator);
void			*ft_realloc(void *ptr, size_t original_size, size_t new_size);

// Parser utils
int				ft_isspace(char c);
int				is_line_empty(char *line);
int				is_valid_extension(char *file_name);
int				ft_isnumber(char *str);

// Conversions utils
float			deg2rad(float angle_degree);
uint32_t		rgba2color(t_rgba rgba);

// Debug utils
void			debug_print(t_game *game);
void			print_map(t_game *game);
void			debug_parse(t_game *game);

// Math utils
void			vec2d_normalize(t_vec2d *v);
t_vec2d			*vec2d_mult_by_scalar(t_vec2d *v, float scalar);
int				min2(int a, int b);
int				max2(int a, int b);
void			clamp(int *val, int min, int max);

#endif