/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:44:59 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/12 19:32:30 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*init_images(t_game *game)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
	{
		image_destroy(game);
		exit(1);
	}
	image->height_image = 64;
	image->width_image = 64;
	image->img_floor = mlx_xpm_file_to_image(game->mlx, "photos/floor.xpm",
			&image->width_image, &image->height_image);
	image->img_collectable = mlx_xpm_file_to_image(game->mlx,
			"photos/collectable.xpm", &image->width_image,
			&image->height_image);
	image->img_exit = mlx_xpm_file_to_image(game->mlx, "photos/exit.xpm",
			&image->width_image, &image->height_image);
	image->img_player = mlx_xpm_file_to_image(game->mlx, "photos/player.xpm",
			&image->width_image, &image->height_image);
	image->img_wall = mlx_xpm_file_to_image(game->mlx, "photos/wall.xpm",
			&image->width_image, &image->height_image);
	return (image);
}

void	place_image_at_position(t_game *game, int x, int y)
{
	void	*image;

	exit_pos(game);
	if (game->map->arr[y][x] == '1')
		image = game->image->img_wall;
	else if (game->map->arr[y][x] == '0')
		image = game->image->img_floor;
	else if (game->map->arr[y][x] == 'P')
	{
		image = game->image->img_player;
		game->player->player_x = x;
		game->player->player_y = y;
	}
	else if (game->map->arr[y][x] == 'C')
		image = game->image->img_collectable;
	else if (count_collectables(game) != 0 && game->map->arr[y][x] == 'E')
		image = game->image->img_floor;
	else if (count_collectables(game) == 0)
	{
		game->map->arr[game->player->exit_y][game->player->exit_x] = 'E';
		image = game->image->img_exit;
	}
	else
		return ;
	mlx_put_image_to_window(game->mlx, game->window, image, x * 64, y * 64);
}

int	element_check(t_game *game, int x, int y)
{
	char	current;

	current = game->map->arr[y][x];
	if (current == '1' || current == '0' || current == 'P' || current == 'C'
		|| current == 'E')
		return (0);
	return (1);
}

int	place_images_on_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map->arr[y] != NULL)
	{
		x = 0;
		while (game->map->arr[y][x])
		{
			place_image_at_position(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	elements(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map->arr[y] != NULL)
	{
		x = 0;
		while (game->map->arr[y][x] && game->map->arr[y][x] != '\n')
		{
			if (element_check(game, x, y) == 1)
			{
				perror("Error\n Invalid character");
				exit_game(game, 0);
			}
			x++;
		}
		y++;
	}
}
