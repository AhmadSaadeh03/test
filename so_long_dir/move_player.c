/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:03:02 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/06 23:04:19 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_player_position(t_game *game)
{
    int i = 0;
    int j = 0;

    while (i < game->map->high)
    {
        j = 0;
        while (j < game->map->width)
        {
            if (game->map->arr[i][j] == 'P')
            {
                game->player->player_x = j;
                game->player->player_y = i;
                return;
            }
            j++;
        }
        i++;
    }
}
void update_move(int new_y, int new_x, t_game *game)
{
    game->map->arr[new_y][new_x] = 'P';
    game->map->arr[game->player->player_y][game->player->player_x] = '0';
    game->player->player_x = new_x;
    game->player->player_y = new_y;
}


void render_game(t_game *game)
{
    mlx_clear_window(game->mlx, game->window);
    place_images_on_map(game);
}

int key_hook(int keycode, t_game *game)
{
    int i = 0;
    int new_x = game->player->player_x;
    int new_y = game->player->player_y;

    printf("Key pressed: %d\n", keycode);  // Debug: Print the keycode when a key is pressed

    // Handle exit with ESC key
    if (keycode == 65307)
    {
        if (game->map)
        {
            // Free the map array first before freeing game->map
            for (int i = 0; i < game->map->high; i++)
                free(game->map->arr[i]);
            free(game->map->arr);
            free(game->map);
        }
        if (game->player)
            free(game->player);
        mlx_destroy_window(game->mlx, game->window);
        free(game);
        exit(0);
    }

    // Player movement logic
    if (keycode == 65361) // Left arrow key
        new_x-=1;
    else if (keycode == 65362) // Up arrow key
        new_y-=1;
    else if (keycode == 65363) // Right arrow key
        new_x+=1;
    else if (keycode == 65364) // Down arrow key
        new_y+=1;
    while (game->map->arr[i])
    {
        printf("%s",game->map->arr[i]);
        i++;
    }
    if (new_x >= 0 && new_x < game->map->width && new_y >= 0 && new_y < game->map->high) // Ensure within map bounds
    {
        if (game->map->arr[new_y][new_x] != '1') // If the new position is not a wall
        {
                update_move(new_y, new_x, game);
                render_game(game);
        }
    }
    return 0;
}


// int key_hook(int keycode, t_game *game)
// {
//     int new_x = game->player->player_x;
//     int new_y = game->player->player_y;
    
//     printf("Key pressed: %d\n", keycode);  // Debug: Print the keycode when a key is pressed
//     if (keycode == 65307)
//     {
//         if (game->map)
//             free(game->map);
//         mlx_destroy_window(game->mlx, game->window);
//         exit(0);
//     }
//     if (keycode == 65361)
//         new_x--;
//     if(keycode == 65362)
//         new_y--;
//     if (keycode == 65363)
//         new_x++;
//     if (keycode == 65364)
//         new_y++;
//     update_move(new_y,new_x,game);
//     render_game(game);
//     return 0;
// }
