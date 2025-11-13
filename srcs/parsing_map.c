/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:10:32 by tabuayya          #+#    #+#             */
/*   Updated: 2025/11/06 20:24:17 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	copy_map(t_parsing *par, char *line)
{
	int	i;

	i = 0;
	par->cp_map = malloc(sizeof(char *) * (par->map_height + 1));
	if (!par->cp_map)
		error_free(line, par, NULL, par->map);
	while (i < par->map_height)
	{
		par->cp_map[i] = ft_strdup(par->map[i]);
		if (!par->cp_map[i])
			error_free(line, par, NULL, par->map);
		i++;
	}
	par->cp_map[i] = NULL;
	return (0);
}

void	flood_fill(t_parsing *par, size_t x, int y)
{
	if (!par->valid)
		return ;
	if (y < 0 || y >= par->map_height || x >= ft_strlen(par->cp_map[y]))
	{
		par->valid = error_message("Out of bounds\n", *par);
		return ;
	}
	if (par->cp_map[y][x] == ' ')
	{
		par->valid = error_message("Space in playable area\n", *par);
		return ;
	}
	if (par->cp_map[y][x] == '1' || par->cp_map[y][x] == 'F')
		return ;
	par->cp_map[y][x] = 'F';
	flood_fill(par, x + 1, y);
	flood_fill(par, x - 1, y);
	flood_fill(par, x, y + 1);
	flood_fill(par, x, y - 1);
	flood_fill(par, x + 1, y + 1);
	flood_fill(par, x - 1, y - 1);
	flood_fill(par, x - 1, y + 1);
	flood_fill(par, x + 1, y - 1);
}

int	parse_map(t_parsing *par, char *line)
{
	if (par->n_char < 1)
		par->valid = error_message("No player in map\n", *par);
	if (!par->valid)
		return (1);
	copy_map(par, line);
	flood_fill(par, par->play_x, par->play_y);
	free_split(par->cp_map);
	return (0);
}
