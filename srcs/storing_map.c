/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:39:50 by tabuayya          #+#    #+#             */
/*   Updated: 2025/11/06 20:26:49 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_ifnotmap(char *line, t_parsing *par)
{
	int	i;

	i = 0;
	while (line[i] && par->valid && line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' ')
			par->valid = error_message("Wrong argument\n", *par);
		i++;
	}
	return (0);
}

int	check_line(char *line, t_parsing *par)
{
	int	i;

	i = 0;
	while (line[i] && par->valid && line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' ')
			par->valid = error_message("Wrong character in map\n", *par);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
		{
			if (par->n_char == 0)
			{
				par->play_x = i;
				par->play_y = par->map_height;
			}
			par->n_char++;
		}
		i++;
	}
	if (par->n_char > 1)
		par->valid = error_message("Too many characters\n", *par);
	return (0);
}

char	*nl_remove(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
	return (line);
}

int	store_map(char *line, t_parsing *par)
{
	char	**new_map;
	int		i;
	int		len;

	len = ft_strlen(line);
	i = 0;
	new_map = malloc(sizeof(char *) * (par->map_height + 2));
	if (!new_map)
		error_free(line, par, NULL, NULL, TRUE);
	while (i < par->map_height)
	{
		new_map[i] = par->map[i];
		i++;
	}
	new_map[i] = ft_strdup(nl_remove(line));
	if (!new_map[i])
		error_free(line, par, NULL, new_map, TRUE);
	new_map[i + 1] = NULL;
	if (par->map)
		free(par->map);
	par->map = new_map;
	par->map_height++;
	if (len > par->longest_line)
		par->longest_line = len;
	return (0);
}

int	validate_map(char *line, t_parsing *par)
{
	if (par->map_ended)
	{
		keep_checking(line, par);
		if (!par->valid)
			return (0);
	}
	if (par->map_started == 0)
		check_ifnotmap(line, par);
	check_all_args(par);
	check_line(line, par);
	if (!skip_empty_line(line, par))
		par->valid = error_message("Empty line in map\n", *par);
	if (!par->valid)
		return (0);
	par->map_started = 1;
	store_map(line, par);
	return (0);
}
