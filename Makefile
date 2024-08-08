# Lib
LIB_PATH		= ./lib

LIBFT_PATH		= $(LIB_PATH)/libft
LIBFT_NAME		= libft.a
LIBFT			= $(LIBFT_PATH)/$(LIBFT_NAME)

LIBMLX_PATH		= $(LIB_PATH)/MLX42
MLX				= $(LIBMLX_PATH)/build/libmlx42.a

# Sources
SRCS_DIR		= ./src/

UTILS_DIR 		= $(SRCS_DIR)/utils/
UTILS_SRCS		= $(UTILS_DIR)/get_next_line/get_next_line.c \
					$(UTILS_DIR)/get_next_line/get_next_line_utils.c

PARSER_DIR		= $(SRCS_DIR)/parser
PARSER_SRCS		= $(PARSER_DIR)/parser.c

SRCS_NO_MAIN	= $(PARSER_SRCS) $(UTILS_SRCS)
SRCS			= src/main.c $(SRCS_NO_MAIN)

# Includes
INCLUDES_PATH	= ./includes

# Compilation
OBJS			= $(MLX) $(LIBFT) ${SRCS:.c=.o}
NAME			= cub3D

CC				= cc
CFLAGS			= -Wextra -Wall -Werror -Ofast
LIBS			= $(MLX) $(LIBFT) -ldl -lglfw -pthread -lm
INC				= -I $(LIBMLX_PATH)/include -I $(LIBFT_PATH) -I $(INCLUDES_PATH)

# Rules
all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(OBJS) $(LIBS) $(INC) -o $(NAME)

%.o: %.c
				$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
				make -C $(LIBFT_PATH) all

$(MLX):
				cmake $(LIBMLX_PATH) -B $(LIBMLX_PATH)/build && make -C $(LIBMLX_PATH)/build -j4

clean:
				make -C $(LIBFT_PATH) clean
				rm -rf $(OBJS)
				rm -rf $(LIBMLX_PATH)/build

fclean: 		clean
				make -C $(LIBFT_PATH) fclean
				rm -rf $(NAME)

re: 			clean all
