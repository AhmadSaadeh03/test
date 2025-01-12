/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:08:08 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/12 18:54:45 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	nullfunction(t_game *game)
{
	game->map = NULL;
	game->player = NULL;
	game->image = NULL;
	game->mlx = NULL;
	game->window = NULL;
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

void	check_error(t_game *game)
{
	size_map(game);
	if (check_wall(game) == 1)
	{
		perror("Error\n not surrounded by walls");
		exit_game(game, 1);
	}
	if (is_rectangle(game) == 1)
	{
		perror("Error\n The map is not rectangle");
		exit_game(game, 1);
	}
	if (count_collectables(game) == 0 || count_exit(game) == 0
		|| count_player(game) == 0)
		exit_game(game, 1);
	if (flood_fill(game) == 0)
	{
		perror("Error:some collectables/exits are unreachable.\n");
		exit_game(game, 1);
	}
	elements(game);
}

t_game	*init_game(char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	nullfunction(game);
	game->player = malloc(sizeof(t_player));
	if (!game->player)
	{
		free(game);
		return (NULL);
	}
	game->map = load_map(game, argv);
	if (!game->map)
		exit_game(game, 1);
	check_error(game);
	size_map(game);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map->width * 64,
			game->map->high * 64, "so_long");
	game->image = init_images(game);
	place_images_on_map(game);
	return (game);
}

int	main(int argc, char *argv[])
{
	t_game	*game;
	int		i;

	if (argc != 2)
		return (0);
	i = 0;
	while (argv[1][i])
		i++;
	i -= 1;
	if (argv[1][i] != 'r' || argv[1][i - 1] != 'e' || argv[1][i - 2] != 'b'
		|| argv[1][i - 3] != '.')
		return (1);
	game = init_game(argv);
	if (!game)
	{
		perror("Error initializing game\n");
		return (1);
	}
	mlx_hook(game->window, 17, 0, free_game, game);
	mlx_key_hook(game->window, key_hook, game);
	mlx_loop(game->mlx);
	exit_game(game, 0);
}
