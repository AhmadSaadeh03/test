/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:44:59 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/06 23:56:26 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void init_images(t_game *game)
{
    int high = 64;
    int width = 64;
    game->image.high_image = high;
    game->image.width_image = width;
    game->image.img_player = mlx_xpm_file_to_image(game->mlx, "photos/player.xpm", &game->image.high_image, &game->image.width_image);
    game->image.img_wall = mlx_xpm_file_to_image(game->mlx, "photos/wall.xpm", &game->image.high_image, &game->image.width_image);
    game->image.img_floor = mlx_xpm_file_to_image(game->mlx, "photos/floor.xpm", &game->image.high_image, &game->image.width_image);
    game->image.img_collectable = mlx_xpm_file_to_image(game->mlx, "photos/collectable.xpm", &game->image.high_image, &game->image.width_image);
    game->image.img_exit = mlx_xpm_file_to_image(game->mlx, "photos/exit.xpm", &game->image.high_image, &game->image.width_image);
}

void place_images_on_map(t_game *game)
{
    int x = 0;
    int y = 0;
    
    while (game->map->arr[y] != NULL)
    {
        x = 0;
        while (game->map->arr[y][x] != '\0')
        {
            if (game->map->arr[y][x] == '1')
            {
                mlx_put_image_to_window(game->mlx, game->window, game->image.img_wall, x * 64, y * 64);
            }
            else if (game->map->arr[y][x] == '0')
            {
                mlx_put_image_to_window(game->mlx, game->window, game->image.img_floor, x * 64, y * 64);
            }
            else if (game->map->arr[y][x] == 'P')
            {
                mlx_put_image_to_window(game->mlx, game->window, game->image.img_player, x * 64, y * 64);
            }
            else if (game->map->arr[y][x] == 'C')
            {
                mlx_put_image_to_window(game->mlx, game->window, game->image.img_collectable, x * 64, y * 64);
            }
            else if (game->map->arr[y][x] == 'E')
            {
                mlx_put_image_to_window(game->mlx, game->window, game->image.img_exit, x * 64, y * 64);
            }

            x++;
        }
        y++;
    }
}
