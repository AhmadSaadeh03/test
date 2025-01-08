/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:09:07 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/08 14:05:50 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     count_lines(char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		exit(1);
	} 	
	while ((line = get_next_line(fd)))
	{
		i++;                      
		free(line);               
		
	}
	close(fd);
	return (i); 
}

t_map *load_map(t_game *game, char *file)
{
    int fd;
    int i;
    int line_count;

    i = 0;
    game->map = malloc(sizeof(t_map));
    if (!game->map)
        return NULL;
    line_count = count_lines(file);
    if (line_count == -1)
        return NULL;
    game->map->arr = malloc(sizeof(char *) * (line_count + 1));
    if (!game->map->arr)
        return NULL;

    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        free(game->map->arr);
        return NULL;
    }

    while (i < line_count)
    {
        game->map->arr[i] = get_next_line(fd);
        if (game->map->arr[i] == NULL)
        {
            // Free allocated memory before returning
            for (int j = 0; j < i; j++)
                free(game->map->arr[j]);
            free(game->map->arr);
            close(fd);
            return NULL;
        }
        i++;
    }
    game->map->arr[i] = NULL;
    close(fd);
    return game->map;
}
void size_map(t_game *game)
{
    int width = 0;
    int height = 0;
    if (game->map->arr[0])
    {
        while (game->map->arr[0][width] != '\n' && game->map->arr[0][width] != '\0')
        width++;
    }
	while(game->map->arr[height])
		height++;
	game->map->high=height;
	game->map->width=width;
}	