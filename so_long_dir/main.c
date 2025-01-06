/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:08:08 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/06 22:26:44 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include <stdlib.h>
// void	nullfunction(t_game *game)
// {
// 	game->map = NULL;
// 	game->player = NULL;
// 	game->image = NULL;
// 	game->mlx = NULL;
// 	game->window = NULL;
// }

// void	image_destroy(t_game *game)
// {
//     t_image *image;
//     image = game->image;
// 	if (image)
// 	{
// 		if (image)
// 			mlx_destroy_image(game->mlx, image->img_wall);
// 		if (image->img_floor)
// 			mlx_destroy_image(game->mlx, image->img_floor);
// 		if (image->img_player)
// 			mlx_destroy_image(game->mlx, image->img_player);
// 		if (image->img_collectable)
// 			mlx_destroy_image(game->mlx, image->img_collectable);
// 		if (image->img_exit)
// 			mlx_destroy_image(game->mlx, image->img_exit);
// 		free(image);
// 		image = NULL;
// 	}
// }

int main(void)
{
    t_game *game;
    game = malloc(sizeof(t_game));
    if (!game)
        return (1); // Handle malloc failure

    game->player = malloc(sizeof(t_player));  // Initialize player
    if (!game->player)
    {
        free(game);
        return (1); // Handle malloc failure
    }

    load_map(game, "test.txt");
    size_map(game);
    game->mlx = mlx_init();
    game->window = mlx_new_window(game->mlx,game->map->width*64,game->map->high * 64, "so_long");
    init_images(game);
    init_player_position(game);
    place_images_on_map(game);
    mlx_key_hook(game->window, key_hook, game);
    mlx_loop(game->mlx);
}


// int	main(void)
// {
//         t_game *game;
//         game = malloc(sizeof(t_game));
//         load_map(game, "test.txt");
//         game->mlx = mlx_init();
// 	    game->window = mlx_new_window(game->mlx, 1000, 550, "so_long");
//         init_images(game);
//         init_player_position(game);
//         place_images_on_map(game);
//         mlx_key_hook(game->window,key_hook,game);
// 	    mlx_loop(game->mlx);
// }

