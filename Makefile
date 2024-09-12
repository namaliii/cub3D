# Lib
LIB_PATH			= ./lib

LIBFT_PATH			= $(LIB_PATH)/libft
LIBFT_NAME			= libft.a
LIBFT				= $(LIBFT_PATH)/$(LIBFT_NAME)

LIBMLX_PATH			= $(LIB_PATH)/MLX42
MLX					= $(LIBMLX_PATH)/build/libmlx42.a

# Sources
SRCS_DIR			= ./src/

GRAPHICS_FILES		= render_frame.c \
						raycast.c \
						minimap.c \
						draw.c \
						put_texture.c

MAP_FILES			= checks.c

PARSER_FILES		= parse.c \
						mock_parse.c \
						player_init.c \
						file_operations.c \
						parse_map.c \
						map_validity.c \
						path_validity.c \
						load_textures.c

PLAYER_FILES		= controls.c

UTILS_FILES			= get_next_line/get_next_line.c \
						get_next_line/get_next_line_utils.c \
						exit_error.c \
						safe_calloc.c \
						rgba2color.c \
						deg2rad.c \
						debug_print.c \
						cub3d_math.c \
						list.c \
						parse_utils.c

GRAPHICS_SRCS		= $(addprefix src/graphics/, $(GRAPHICS_FILES))
MAP_SRCS			= $(addprefix src/map/, $(MAP_FILES))
PARSER_SRCS			= $(addprefix src/parser/, $(PARSER_FILES))
PLAYER_SRCS			= $(addprefix src/player/, $(PLAYER_FILES))
UTILS_SRCS			= $(addprefix src/utils/, $(UTILS_FILES))

SRCS_NO_MAIN		= $(GRAPHICS_SRCS) $(MAP_SRCS) $(PARSER_SRCS) $(PLAYER_SRCS) $(UTILS_SRCS)
SRCS				= src/main.c $(SRCS_NO_MAIN)

# Includes
INCLUDES_PATH		= ./includes

# Compilation
OBJS_DIR             = obj
OBJS				= $(MLX) $(LIBFT) $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
NAME				= cub3D

CC					= cc
CFLAGS				= -Wextra -Wall -Werror -g3
LIBS				= $(MLX) $(LIBFT) -ldl -lglfw -pthread -lm
INC					= -I $(LIBMLX_PATH)/include/MLX42 -I $(LIBFT_PATH) -I $(INCLUDES_PATH)

# Rules
all:				$(NAME)

$(NAME):			$(OBJS)
					@$(CC) $(OBJS) $(LIBS) $(INC) -o $(NAME)
					@echo "cub3d created"

$(OBJS_DIR)/%.o: %.c
					@mkdir -p $(dir $@)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
					@printf "%-18s" "Building libft..."
					@make -C $(LIBFT_PATH) all --silent
					@echo " DONE"

$(MLX):
					@printf "%-18s" "Building MLX..."
					@cmake -S $(LIBMLX_PATH) -B $(LIBMLX_PATH)/build --log-level=ERROR > /dev/null && make -C $(LIBMLX_PATH)/build -j4 > /dev/null
					@echo " DONE"

clean:
					@printf "%-18s" "Cleaning..."
					@make -C $(LIBFT_PATH) clean --silent
					@rm -rf $(OBJS)
					@rm -rf $(LIBMLX_PATH)/build
					@echo " DONE"

fclean: 			clean
					@printf "%-18s" "Full cleaning..."
					@make -C $(LIBFT_PATH) fclean --silent
					@rm -rf $(NAME)
					@echo " DONE"

re:		 			clean all
# Paths to libraries
# LIB_PATH            = ./lib

# # Paths to libft and MLX libraries
# LIBFT_PATH          = $(LIB_PATH)/libft
# LIBFT_NAME          = libft.a
# LIBFT               = $(LIBFT_PATH)/$(LIBFT_NAME)

# LIBMLX_PATH         = $(LIB_PATH)/MLX42
# MLX                 = $(LIBMLX_PATH)/build/libmlx42.a

# # Directories and files for sources
# SRCS_DIR            = ./src/

# GRAPHICS_FILES      = render_frame.c \
#                       raycast.c \
#                       minimap.c \
#                       draw.c \
# 					  put_texture.c

# MAP_FILES           = checks.c

# PARSER_FILES        = parse.c \
#                       mock_parse.c \
#                       player_init.c \
#                       file_operations.c \
#                       parse_map.c \
#                       map_validity.c \
#                       path_validity.c \
#                       load_textures.c

# PLAYER_FILES        = controls.c

# UTILS_FILES         = get_next_line/get_next_line.c \
#                       get_next_line/get_next_line_utils.c \
#                       exit_error.c \
#                       safe_calloc.c \
#                       rgba2color.c \
#                       deg2rad.c \
#                       debug_print.c \
#                       cub3d_math.c \
#                       list.c \
#                       parse_utils.c

# # Combine all source files
# GRAPHICS_SRCS       = $(addprefix src/graphics/, $(GRAPHICS_FILES))
# MAP_SRCS            = $(addprefix src/map/, $(MAP_FILES))
# PARSER_SRCS         = $(addprefix src/parser/, $(PARSER_FILES))
# PLAYER_SRCS         = $(addprefix src/player/, $(PLAYER_FILES))
# UTILS_SRCS          = $(addprefix src/utils/, $(UTILS_FILES))

# SRCS_NO_MAIN        = $(GRAPHICS_SRCS) $(MAP_SRCS) $(PARSER_SRCS) $(PLAYER_SRCS) $(UTILS_SRCS)
# SRCS                = src/main.c $(SRCS_NO_MAIN)

# # Include paths
# INCLUDES_PATH       = ./includes

# # Compilation settings
# OBJS_DIR            = obj
# OBJS                = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
# NAME                = cub3D

# CC                  = cc
# CFLAGS              = -Wextra -Wall -Werror -g3 -fsanitize=address
# LIBS                = $(MLX) $(LIBFT) -ldl -lglfw -pthread -lm
# INC                 = -I $(LIBMLX_PATH)/include/MLX42 -I $(LIBFT_PATH) -I $(INCLUDES_PATH)

# # Rules to build the project
# all:                $(NAME)

# $(NAME):            $(OBJS) $(LIBFT) $(MLX)
# 	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(INC) -o $(NAME)
# 	@echo "cub3D created"

# $(OBJS_DIR)/%.o: %.c
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# $(LIBFT):
# 	@printf "%-18s" "Building libft..."
# 	@make -C $(LIBFT_PATH) all --silent
# 	@echo " DONE"

# $(MLX):
# 	@printf "%-18s" "Building MLX..."
# 	@cmake -S $(LIBMLX_PATH) -B $(LIBMLX_PATH)/build --log-level=ERROR > /dev/null && make -C $(LIBMLX_PATH)/build -j4 > /dev/null
# 	@echo " DONE"

# clean:
# 	@printf "%-18s" "Cleaning..."
# 	@make -C $(LIBFT_PATH) clean --silent
# 	@rm -rf $(OBJS_DIR)
# 	@rm -rf $(LIBMLX_PATH)/build
# 	@echo " DONE"

# fclean:             clean
# 	@printf "%-18s" "Full cleaning..."
# 	@make -C $(LIBFT_PATH) fclean --silent
# 	@rm -rf $(NAME)
# 	@echo " DONE"

# re:                 fclean all

# .PHONY: all clean fclean re
