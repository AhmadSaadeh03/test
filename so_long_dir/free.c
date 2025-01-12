/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:08:30 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/11 17:58:52 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game *game, int bool)
{
	if (game)
	{
		if (game->image)
		{
			free_images(game);
			free(game->image);
		}
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		if (game->player)
			free(game->player);
		if (game->map)
			free_map(game);
		free(game);
	}
	exit(bool);
}

void	free_images(t_game *game)
{
	if (game->image)
	{
		if (game->image->img_wall)
			mlx_destroy_image(game->mlx, game->image->img_wall);
		if (game->image->img_floor)
			mlx_destroy_image(game->mlx, game->image->img_floor);
		if (game->image->img_exit)
			mlx_destroy_image(game->mlx, game->image->img_exit);
		if (game->image->img_player)
			mlx_destroy_image(game->mlx, game->image->img_player);
		if (game->image->img_collectable)
			mlx_destroy_image(game->mlx, game->image->img_collectable);
	}
}

void	free_map(t_game *game)
{
	int	i;

	if (game->map->arr)
	{
		i = 0;
		while (game->map->arr[i])
		{
			free(game->map->arr[i]);
			i++;
		}
		free(game->map->arr);
		free(game->map);
	}
}

int	free_game(t_game *game)
{
	exit_game(game, 1);
	exit(1);
}
