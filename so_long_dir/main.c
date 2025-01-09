/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:08:08 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/09 19:00:02 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_game(t_game *game)
{
	exit_game(game);
	exit(1);
}
void	image_destroy(t_game *game)
{
	t_image	*image;

	image = game->image;
	if (image)
	{
		if (image)
			mlx_destroy_image(game->mlx, image->img_wall);
		if (image->img_floor)
			mlx_destroy_image(game->mlx, image->img_floor);
		if (image->img_player)
			mlx_destroy_image(game->mlx, image->img_player);
		if (image->img_collectable)
			mlx_destroy_image(game->mlx, image->img_collectable);
		if (image->img_exit)
			mlx_destroy_image(game->mlx, image->img_exit);
		free(image);
		image = NULL;
	}
}
void check_error(t_game *game)
{
	int		s;
	int		collectable;
	int		player;
	int		exit;
	int 	check ;
	size_map(game);
	check = check_wall(game);
	if (check == 1)
		exit_game(game);
	s = is_rectangle(game);
	if (s == 1)
		exit_game(game);
	collectable = count_collectables(game);
	player = count_player(game);
	exit = count_exit(game);
	if (collectable == 0 || exit == 0 || player == 0)
		exit_game(game);
}

int	main(void)
{
	t_game	*game;
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	game->player = malloc(sizeof(t_player));
	if (!game->player)
	{
		free(game);
		return (1);
	}
	load_map(game, "test.txt");
	check_error(game);
	size_map(game);
	exit_pos(game);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map->width * 64,
			game->map->high * 64, "so_long");
	game->image = init_images(game);
	place_images_on_map(game);
	if (flood_fill(game) == 0)
	{
    		printf("Error: Map is not fully connected or some collectables/exits are unreachable.\n");
    		exit_game(game);
	}
	mlx_hook(game->window, 17, 0, free_game, game);
	mlx_key_hook(game->window, key_hook, game);
	mlx_loop(game->mlx);
}