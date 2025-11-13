/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:21:35 by tabuayya          #+#    #+#             */
/*   Updated: 2025/11/06 20:22:27 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_commas(char *line, t_parsing *par)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			counter++;
		i++;
	}
	if (counter != 2)
		par->valid = error_message("Wrong amount of arguments\n", *par);
	return (0);
}

int	check_number(char *trim, t_parsing *par)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	if (trim[0] == '+')
		i++;
	while (trim[i])
	{
		if (trim[i] > '9' || trim[i] < '0')
			par->valid = error_message("Wrong arguments in color\n", *par);
		i++;
	}
	if (i > 4)
		par->valid = error_message("Color not within range\n", *par);
	num = ft_atoi(trim);
	if (num < 0 || num > 255)
		par->valid = error_message("Color not within range\n", *par);
	return (num);
}

int	validate_color(char *s_line, t_parsing *par, char *line)
{
	int		i;
	char	**split_line;
	char	*trim;
	int		j;

	j = 0;
	i = 0;
	trim = NULL;
	split_line = ft_split(s_line, ',');
	if (!split_line)
		error_free(s_line, par, line, NULL, TRUE);
	check_commas(s_line, par);
	check_args(s_line, par, line, split_line);
	while (split_line[i] && j < 3)
	{
		trim = ft_strtrim(split_line[i], " \n\v\r\t");
		if (!trim)
			error_free(s_line, par, line, split_line, TRUE);
		par->col[j] = check_number(trim, par);
		free(trim);
		i++;
		j++;
	}
	free_split(split_line);
	return (0);
}

int	store_color(t_parsing *par)
{
	int	i;

	i = 0;
	if (ft_strcmp(par->id, "F") == 0)
	{
		while (i < 3)
		{
			par->f_col[i] = par->col[i];
			i++;
		}
	}
	else if (ft_strcmp(par->id, "C") == 0)
	{
		while (i < 3)
		{
			par->c_col[i] = par->col[i];
			i++;
		}
	}
	return (0);
}

int	check_color(char *line, t_parsing *par)
{
	char	*sub_line;

	if (ft_strcmp(par->id, "F") == 0)
		par->valid_color_f++;
	else if (ft_strcmp(par->id, "C") == 0)
		par->valid_color_c++;
	if (par->valid_color_c > 1 || par->valid_color_f > 1)
		par->valid = error_message("Too many arguments\n", *par);
	if (!par->valid)
		return (0);
	sub_line = get_substring(line, par);
	validate_color(sub_line, par, line);
	store_color(par);
	free(sub_line);
	return (0);
}
