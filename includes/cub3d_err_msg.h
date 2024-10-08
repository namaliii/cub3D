/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_err_msg.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:38:59 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/20 13:05:02 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERR_MSG_H
# define CUB3D_ERR_MSG_H

# define ERR_MSG_ALLOC "Error\nAllocation failed."
# define ERR_MSG_INVALID_ARGC "Error\nWrong number of arguments!"
# define ERR_MSG_INVALID_WALK_SPEED \
	"Error\nCompiled with walking speed too big."
# define ERR_MSG_INVALID_COL_DIST_TOO_SMALL \
	"Error\nCollision distance multiplier cannot be smaller than 1."
# define ERR_MSG_INVALID_COL_DIST_WALK_SPEED \
	"Error\nCollision distance times walking speed cannot exceed 1."
# define ERR_MSG_INVALID_OUT_OF_BOUNDS_TILE \
	"Error\nOut of bounds tile must be a solid type."

# define ERR_MSG_FAILED_TO_DUP_LINE "Error\nFailed to duplicate line"
# define ERR_MSG_FAILED_OPENING_FILE "Error\nFailed to open the file"
# define ERR_MSG_FILE_EMPTY "Error\nThe file is empty!"

// Parsing identifiers
# define ERR_MSG_MISSING_IDENTIFIERS \
	"Error\nOne or more identifiers are missing"
# define ERR_MSG_MULTIPLE_IDENTIFIERS \
	"Error\nSome identifiers are defined multiple times"
# define ERR_MSG_INVALID_IDENTIFIER "Error\nInvalid identifier"

// Parsing colors
# define ERR_MSG_INVALID_COLORS \
	"Error\nColors are beyond the proper scope, please adjust to 0 - 255"
# define ERR_MSG_COLOR_INVALID_NUM_CHNLS \
	"Error\nColors have invalid number of channels"
# define ERR_MSG_INV_CHAR_IN_COLR "Error\nInvalid character in color"
# define ERR_MSG_COLOR_EXPECTS_MORE_LINES "Error\nColor expects new lines after"
# define ERR_MSG_EMPTY_COLOR "Error\nColor value is empty"

// Parsing map
# define ERR_MSG_INVALID_MAP_SIZE \
	"Error\nSize of the map causes stack overflow! Create a smaller map."
# define ERR_MSG_MAP_NOT_ONE_PIECE "Error\nMap has to be one piece"
# define ERR_MSG_MAP_VAL_CHCK_COPY_FAIL \
	"Error\nFailed to copy map for path validity check."
# define ERR_MSG_MAP_INVALID_CHARS "Error\nMap contains invalid characters!"
# define ERR_MSG_MAP_NOT_ENCLOSED "Error\nMap is not surrounded by the walls!"
# define ERR_MSG_MAP_INVALID "Error\nMap is invalid!"
# define ERR_MSG_MAP_EMPTY_LINE "Error\nEmpty line in map!"
# define ERR_MSG_MAP_EXT_INVALID "Error\nMap extension invalid"
# define ERR_MSG_FAILED_TO_REALLOC_MAP \
	"Error\nFailed to reallocate the map for adding a new line while parsing"

// Parsing player
# define ERR_MSG_INVALID_NUM_OF_PLAYERS \
	"Error\nThere's more than one player chars"
# define ERR_MSG_NO_PLAYERS "Error\nThere's no player char"

// Parsing texture
# define ERR_MSG_LOADING_TEXTURE "Error\nTexture loading error"

#endif