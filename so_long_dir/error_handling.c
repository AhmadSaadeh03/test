/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:01:10 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/08 15:21:29 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(t_game *game)
{
	size_t len;
	int		i;

	len = removeln(game->map->arr[0]);
	i = 0;
	while (game->map->arr[i])
	{
		if (removeln(game->map->arr[i]) != len)
		{
			perror("Error: The map is not rectangle.");
			return (1);
		}
		i++;
	}
        return (0);
}

size_t	removeln(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	return (len);
}