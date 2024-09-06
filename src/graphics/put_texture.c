/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:17:10 by anamieta          #+#    #+#             */
/*   Updated: 2024/09/06 19:40:51 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float calculate_wall_hit_x(float ray_angle, float player_x)
{
    float wall_hit_x = player_x + (ray_angle * cos(ray_angle));
    return wall_hit_x;
}

int calculate_texture_x_offset(float wall_hit_x, t_game *game)
{
    mlx_texture_t *texture = game->tex_no;
    int texture_width = texture->width;
    float texture_x_offset_float = wall_hit_x - floor(wall_hit_x);
    int texture_x_offset = (int)(texture_x_offset_float * texture_width) % texture_width;
    if (texture_x_offset < 0)
        texture_x_offset += texture_width;
    return texture_x_offset;
}

void draw_textured_wall(t_game *game, int x, int wall_start_px, int wall_end_px)
{
    float ray_angle = (game->p_angle_rad + game->fov_rad / 2) - ((double)x / (double)game->scr_width) * game->fov_rad;
    float wall_hit_x = calculate_wall_hit_x(ray_angle, game->px);
    int texture_x_offset = calculate_texture_x_offset(wall_hit_x, game);
    mlx_texture_t *texture = game->tex_no;
    int texture_width = texture->width;
    int texture_height = texture->height;
    int wall_height = wall_end_px - wall_start_px;
    double step = (double)texture_height / wall_height;
    int y = wall_start_px;
    while (y < wall_end_px)
    {
        int texture_y = (int)((y - wall_start_px) * step);
        texture_y = min2(max2(texture_y, 0), texture_height - 1);
        int color = (texture->pixels[(texture_y * texture_width + texture_x_offset) * 4] << 24)
                    | (texture->pixels[(texture_y * texture_width + texture_x_offset) * 4 + 1] << 16)
                    | (texture->pixels[(texture_y * texture_width + texture_x_offset) * 4 + 2] << 8)
                    | (texture->pixels[(texture_y * texture_width + texture_x_offset) * 4 + 3]);
        if (x < game->scr_width && y < game->scr_height && x >= 0 && y >= 0)
            mlx_put_pixel(game->img, x, y, color);
        y++;
    }
}

// void	draw_textured_wall(t_game *game, int x, int wall_start_px, int wall_end_px)
// {
//     mlx_texture_t *texture = game->tex_no;
//     int texture_width = texture->width;
//     int texture_height = texture->height;
//     int wall_height = wall_end_px - wall_start_px;
//     double step = (double)texture_height / wall_height;
//     // double step = (double)wall_height / texture_height;
//     int texture_x = x % texture_width;
//     int y = wall_start_px;
//     while (y < wall_end_px)
//     {
//         int texture_y = step * (int)(y - wall_start_px);
//         texture_y = min2(max2(texture_y, 0), texture_height - 1);
//         int color = (texture->pixels[(texture_y * texture_width + texture_x) * 4] << 24)
//                     | (texture->pixels[(texture_y * texture_width + texture_x) * 4 + 1] << 16)
//                     | (texture->pixels[(texture_y * texture_width + texture_x) * 4 + 2] << 8)
//                     | (texture->pixels[(texture_y * texture_width + texture_x) * 4 + 3]);
//         if (x < SCREEN_WIDTH && y < SCREEN_HEIGHT && x > 0 && y > 0)
//             mlx_put_pixel(game->img, x, y, color);
//         y++;
//     }
// }
