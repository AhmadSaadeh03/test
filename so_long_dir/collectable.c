/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:19:11 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/11 15:23:48 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collectables(t_game *game)
{
	int count = 0;
	int y = 0;
	int x = 0;

	while (game->map->arr[y])
	{
		x = 0;
		while (game->map->arr[y][x])
		{
			if (game->map->arr[y][x] == 'C')
			{
				count++;
			}
			x++;
		}
		y++;
	}
	if (count == 0)
		return (0);
	game->map->count_collectable = count;
	return (game->map->count_collectable);
}