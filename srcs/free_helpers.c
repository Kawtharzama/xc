/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabu-zee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:01:02 by kabu-zee          #+#    #+#             */
/*   Updated: 2025/11/13 19:01:04 by kabu-zee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_data *data)
{
	int	y;

	if (!data->gameMap)
		return ;
	y = 0;
	while (y < data->parse.map_height)
	{
		if (data->gameMap[y])
			free(data->gameMap[y]);
		y++;
	}
	free(data->gameMap);
	data->gameMap = NULL;
}

void	free_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		free(data->texture[i]);
		data->texture[i] = NULL;
		i++;
	}
}

void	free_textures_paths_and_map(t_data *data)
{
	free_map(data);
	free_textures(data);
}

void	free_exit(t_data *data, char *str, bool mlx_ter, bool exit_game)
{
	if (str)
		printf("%s", str);
	if (mlx_ter == TRUE)
	{
		mlx_terminate(data->mlx);
	}
	free_textures_paths_and_map(data);
	error_free(NULL, &data->parse, data->parse.trim, data->parse.map,
		exit_game);
}
