/* ************************************************************************** */
/*		                                                                    */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:22:52 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/10 16:01:32 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "lib/libft/libft.h"
# include "lib/MLX42/include/MLX42/MLX42.h"

# define WIN_WIDTH 640
# define WIN_HEIGHT 480

void	parser(int argc, char *argv[]);

typedef struct s_point
{
	int x;
	int y;
}			   t_point;

typedef struct s_data
{
	mlx_t   *mlx;
}			   t_data;

#endif
