/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:33:01 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/06 23:54:16 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
#include <mlx.h>

typedef struct s_map
{
        int high;
        int width;
        char **arr;
}t_map;
typedef struct s_image
{
        void    *img_player; 
        void    *img_wall; 
        void    *img_floor; 
        void    *img_collectable;
        void    *img_exit;
        int height_image;
        int width_image;
}t_image;

typedef struct s_player
{
        int player_x;
        int player_y;
}t_player;
typedef struct s_game
{
        void *mlx;
        void *window;
        t_map *map;
        t_image image;
        t_player *player;
}t_game;

void size_map(t_game *game);
t_map	*load_map(t_game *game,char *file);
int     count_lines(char *file);
void open_window(t_game *game);
void    init_images(t_game *game);
void place_images_on_map(t_game *game);
int key_hook(int keycode, t_game *game);
void render_game(t_game *game);
void init_player_position(t_game *game);
void update_move(int new_y,int new_x,t_game *game);
int is_valid_move(int new_y, int new_x, t_game *game);
// void	image_destroy(t_game *game);
////////////////////////////////////////
void	moving(t_game *game, int new_x, int new_y);
void	key_move(int keycode, t_game *game);
int	close_window(t_game *game);
int	handle_keypress(int keycode, void *param);
void	init_photos(t_image *image, t_game *game);
void	put_image(t_image *image, t_game *game, int x, int y);
void	map_runder(t_image *image, t_game *game);


#endif