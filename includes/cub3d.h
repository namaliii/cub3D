/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:52 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/21 15:30:31 by tunsal           ###   ########.fr       */
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

# define PI 3.141592
# define FOV 60
# define TURN_ANGLE 4.6875
# define WALK_SPEED 6.25
# define MAX_WALK_SPEED 0.95
# define MOUSE_SENSITIVITY 0.001
# define COLLISION_DIST_MULTIPLIER 2
# define FPS_UNLIMITED 0
# define FPS_STR_SIZE 12

# define TILE_WALL '1'
# define TILE_DOOR_CLOSED_CHAR 'D'
# define TILE_DOOR_OPENED_CHAR 'd'
# define TILE_SPACE ' '
# define TILE_OUT_OF_BOUNDS TILE_DOOR_CLOSED_CHAR
# define DOOR_TEX_PATH "./img/door.png"
# define DIRECTION_OFFSET_COUNT 8
# define IDENTIFIER_COUNT 6

# define SPRITE_FRAME_RATE 10
# define SPRITE_FRAMES 8
# define SPRITE_BASE_PATH "./img/sprite/torch"
# define SPRITE_FILE_PATH_LEN 256

# define COLOR_ALPHA_CHANNEL_MASK 0xFF000000

enum e_parsing_state
{
	PARSING_STATE_IDENTIFIERS,
	PARSING_STATE_WAITING_MAP,
	PARSING_STATE_MAP
};

enum e_hit_direction
{
	HIT_VERTICAL_WALL,
	HIT_HORIZONTAL_WALL,
	HIT_DOOR
};

typedef struct s_sprite
{
	mlx_texture_t	*frames[SPRITE_FRAMES];
	int				current_frame;
	double			sway_offset;
	double			time_accumulator_sec;
	int				direction;
}	t_sprite;

typedef struct s_ray_hit
{
	int		side;
	char	hit_tile_type;
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
	bool			identifiers[IDENTIFIER_COUNT];
	t_sprite		sprite;
	double			last_time_sec;
	double			delta_time_sec;
	int				fps_limit;
	double			fps_time_accumulator_sec;
	unsigned int	fps_frame_count;
	char			*fps_str;
	int				map_fd;
}	t_game;

typedef struct s_dda_vars
{
	float	step_x;
	float	step_y;
	float	dist_intersect_x;
	float	dist_intersect_y;
	int		dir_x;
	int		dir_y;
	int		map_x;
	int		map_y;
	float	init_side_dist_x;
	float	init_side_dist_y;
	int		hit ;
	int		side;
	float	perp_wall_dist;
}	t_dda_vars;

// Main
void			init_game(t_game *game);
void			load_textures(t_game *game);

// Graphics
void			render_frame(t_game *game);
void			raycast(t_game *game);
void			find_dist(float angle, t_game *game, t_ray_hit *p_ray_hit);
void			draw_minimap(t_game *game);
void			draw_rect(t_game *game, t_rect r);
void			draw_safe_rect(t_game *game, t_rect r);
void			draw_textured_wall(t_game *game, int x, float ray_angle,
					t_ray_hit *hit_info);
void			handle_sprite_animation(t_game *game);
uint32_t		rgba2color(t_rgba rgba);
uint32_t		get_mlx_texture_pixel(mlx_texture_t *tex, int x, int y);
bool			is_fully_transparent(uint32_t color);

// Map
bool			is_map_tile_solid(t_game *game, int x, int y);
char			get_map_tile(t_game *game, int x, int y);
bool			is_out_of_bounds(t_game *game, int x, int y);
bool			is_tile_solid(char tile);
void			toggle_door(t_game *game, int door_x, int door_y);
void			toggle_door_safe(t_game *game, int door_x, int door_y);

// Parser
int				parse(int argc, char **argv, t_game *game);
void			parse_map_line(t_game *game, char *line);
void			parse_identifier_line(t_game *game, char *line);
void			parse_rgb(t_game *game, char *line, t_rgba *color);
void			assign_textures(
					t_game *game, mlx_texture_t **tex_img, char *line);
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
void			*safe_calloc(size_t elems_count, size_t elem_size);
int				find_splits_length(char **splits);
void			print_usage(int argc, char **argv);
char			**ft_split_e(char const *str, char separator);
void			*ft_realloc(void *ptr, size_t original_size, size_t new_size);

// Cleanup utils
void			cleanup_parser(t_game *game);
void			cleanup_textures(t_game *game);
void			cleanup_mlx(t_game *game);
void			total_cleanup(t_game *game);

// Exit utils
void			exit_error(const char *msg);
void			exit_error_mlx(t_game *game, const char *msg);
void			exit_error_parser(t_game *game, const char *msg);
void			exit_error_cleanup_textures(t_game *game, const char *msg);
void			free_2d_array(char **array, int height);

// Parser utils
int				ft_isspace(char c);
int				is_line_empty(char *line);
int				is_valid_extension(char *file_name);
int				ft_isnumber(char *str);

// Angle utils
float			deg2rad(float angle_degree);
void			angle_bound(float *angle_rad);
float			angle_subt(float a_rad, float b_rad);
float			angle_add(float a_rad, float b_rad);

// Debug utils
void			debug_print(t_game *game);
void			print_map(t_game *game);
void			debug_parse(t_game *game);
void			print_string_arr(char **str_arr);
void			print_vec2d(t_vec2d *v);

// Math utils
void			vec2d_normalize(t_vec2d *v);
t_vec2d			*vec2d_mult_by_scalar(t_vec2d *v, float scalar);
int				min2(int a, int b);
float			min2f(float a, float b);
int				max2(int a, int b);
void			clamp(int *val, int min, int max);

#endif