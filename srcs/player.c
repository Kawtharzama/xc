/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabu-zee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:01:56 by kabu-zee          #+#    #+#             */
/*   Updated: 2025/11/13 19:01:58 by kabu-zee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_north(t_data *data)
{
	data->player.dirX = 0;
	data->player.dirY = -1;
	data->player.planeX = 0.66;
	data->player.planeY = 0;
}

static void	set_player_south(t_data *data)
{
	data->player.dirX = 0;
	data->player.dirY = 1;
	data->player.planeX = -0.66;
	data->player.planeY = 0;
}

static void	set_player_east(t_data *data)
{
	data->player.dirX = 1;
	data->player.dirY = 0;
	data->player.planeX = 0;
	data->player.planeY = 0.66;
}

static void	set_player_west(t_data *data)
{
	data->player.dirX = -1;
	data->player.dirY = 0;
	data->player.planeX = 0;
	data->player.planeY = -0.66;
}

void	init_player(t_data *data, int x, int y)
{
	data->player.posX = x;
	data->player.posX += 0.5;
	data->player.posY = y;
	data->player.posY += 0.5;
	if (data->parse.map[y][x] == 'N')
		set_player_north(data);
	else if (data->parse.map[y][x] == 'S')
		set_player_south(data);
	else if (data->parse.map[y][x] == 'E')
		set_player_east(data);
	else if (data->parse.map[y][x] == 'W')
		set_player_west(data);
	data->gameMap[y][x] = 0;
}
