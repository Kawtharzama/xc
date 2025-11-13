/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabu-zee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:01:44 by kabu-zee          #+#    #+#             */
/*   Updated: 2025/11/13 19:01:46 by kabu-zee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	alloc_row_or_exit(t_data *data, int y)
{
	data->gameMap[y] = (int *)ft_calloc(data->parse.longest_line, sizeof(int));
	if (!data->gameMap[y])
		free_exit(data, "Map memory allocation failed", FALSE, TRUE);
}

void	process_map_row(t_data *data, int y)
{
	int		x;
	char	c;

	alloc_row_or_exit(data, y);
	x = 0;
	while (x < data->parse.longest_line)
	{
		c = data->parse.map[y][x];
		if (c == '1')
			data->gameMap[y][x] = 1;
		else if (c == '0')
			data->gameMap[y][x] = 0;
		else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			init_player(data, x, y);
		else
			data->gameMap[y][x] = 1;
		x++;
	}
}

void	init_map_n_player(t_data *data)
{
	int	y;

	data->gameMap = (int **)ft_calloc(data->parse.map_height, sizeof(int *));
	if (!data->gameMap)
		free_exit(data, "Map memory allocation failed", FALSE, TRUE);
	y = 0;
	while (y < data->parse.map_height)
	{
		process_map_row(data, y);
		y++;
	}
}
