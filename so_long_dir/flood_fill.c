/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:41:15 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/09 18:54:47 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_fill_helper(t_game *game, int y, int x, int **visited) {
    if (y < 0 || y >= game->map->high || x < 0 || x >= game->map->width)
        return;
    if (game->map->arr[y][x] == '1' || visited[y][x])
        return;
    visited[y][x] = 1;
    flood_fill_helper(game, y + 1, x, visited);
    flood_fill_helper(game, y - 1, x, visited);
    flood_fill_helper(game, y, x + 1, visited);
    flood_fill_helper(game, y, x - 1, visited);
}
int flood_fill(t_game *game) {
    int **visited;
    int i, j;
    visited = malloc(sizeof(int *) * game->map->high);
    if (!visited)
        return 0;
    i = 0;
    while (i < game->map->high) {
        visited[i] = malloc(sizeof(int) * game->map->width);
        if (!visited[i]) {
            while (i-- > 0)
                free(visited[i]);
                 free(visited);
            return 0;
        }
        j = 0;
        while (j < game->map->width) {
            visited[i][j] = 0;
            j++;
        }
        i++;
    }
    flood_fill_helper(game, game->player->player_y, game->player->player_x, visited);
    int reachable = 1;
    i = 0;
    while (i < game->map->high && reachable) {
        j = 0;
        while (j < game->map->width && reachable) {
            if ((game->map->arr[i][j] == 'C' || game->map->arr[i][j] == 'E') && !visited[i][j]) {
                reachable = 0;
            }
            j++;
        }
        i++;
    }
    i = 0;
    while (i < game->map->high) {
        free(visited[i]);
        i++;
    }
    free(visited);
    return reachable;
}
