/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_err_msg.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:38:59 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/13 10:53:42 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERR_MSG_H
# define CUB3D_ERR_MSG_H

# define ERR_MSG_ALLOC "Error: Allocation failed."
# define ERR_MSG_INVALID_COLORS \
	"Colors are beyond the proper scope, please adjust to 0 - 255"
# define ERR_MSG_INVALID_ARGC "Wrong number of arguments!"
# define ERR_MSG_INVALID_MAP_SIZE \
	"Size of the map causes stack overflow! Create a smaller map."
# define ERR_MSG_INVALID_CHAR_IN_COLOR "Invalid character in color"
# define ERR_MSG_FAILED_TO_DUP_LINE "Failed to duplicate line"
# define ERR_MSG_MAP_NOT_ONE_PIECE "Map has to be one piece"
# define ERR_MSG_MAP_VAL_CHCK_COPY_FAIL \
	"Failed to copy map for path validity check."
# define ERR_MSG_INVALID_NUM_OF_PLAYERS "There's more than one player chars"
# define ERR_MSG_NO_PLAYERS "There's no player char"
# define ERR_MSG_MAP_INVALID_CHARS "Map contains invalid characters!"
# define ERR_MSG_MAP_NOT_ENCLOSED "Map is not surrounded by the walls!"
# define ERR_MSG_MAP_INVALID "Map is invalid!"
# define ERR_MSG_LOADING_TEXTURE "Texture loading error"
# define ERR_MSG_FILE_EMPTY "The file is empty!"
# define ERR_MSG_MAP_EMPTY_LINE "Empty line in map!"
# define ERR_MSG_FAILED_OPENING_FILE "Failed to open the file"

#endif