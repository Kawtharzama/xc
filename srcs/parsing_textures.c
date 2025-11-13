/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:53:03 by tabuayya          #+#    #+#             */
/*   Updated: 2025/11/06 20:30:24 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_path(char *path, t_parsing *par)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		par->valid = error_message("file not available\n", *par);
	return (0);
}

int	check_repeats(t_parsing *par)
{
	if (ft_strcmp(par->id, "NO") == 0)
		par->text_no++;
	else if (ft_strcmp(par->id, "SO") == 0)
		par->text_so++;
	else if (ft_strcmp(par->id, "EA") == 0)
		par->text_ea++;
	else if (ft_strcmp(par->id, "WE") == 0)
		par->text_we++;
	if (par->text_no > 1 || par->text_so > 1 || par->text_ea > 1
		|| par->text_we > 1)
		par->valid = error_message("Too many arguments\n", *par);
	return (0);
}

int	check_args_text(char *line, t_parsing *par)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
		{
			count++;
			while (line[i] != ' ' && line[i] != '\t' && line[i]
				&& line[i] != '\n')
				i++;
		}
		else
			i++;
	}
	if (count != 2)
		par->valid = error_message("Wrong number of arguments1\n", *par);
	return (0);
}

void	store_textures(char *line, t_parsing *par)
{
	if (ft_strcmp(par->id, "NO") == 0)
	{
		par->NO_path = ft_strdup(par->subline);
		if (!par->NO_path)
			error_free(line, par, par->subline, NULL, TRUE);
	}
	else if (ft_strcmp(par->id, "SO") == 0)
	{
		par->SO_path = ft_strdup(par->subline);
		if (!par->SO_path)
			error_free(line, par, par->subline, NULL, TRUE);
	}
	else if (ft_strcmp(par->id, "EA") == 0)
	{
		par->EA_path = ft_strdup(par->subline);
		if (!par->EA_path)
			error_free(line, par, par->subline, NULL, TRUE);
	}
	else if (ft_strcmp(par->id, "WE") == 0)
	{
		par->WE_path = ft_strdup(par->subline);
		if (!par->WE_path)
			error_free(line, par, par->subline, NULL, TRUE);
	}
}

int	check_textures(char *line, t_parsing *par)
{
	par->trim = ft_strtrim(line, " \a\b\f\n\r\t\v");
	if (!par->trim)
		error_free(line, par, par->trim, NULL, TRUE);
	par->subline = get_substring(line, par);
	check_repeats(par);
	check_args_text(par->trim, par);
	check_path(par->subline, par);
	if (!par->valid)
	{
		if (par->subline)
			free(par->subline);
		if (par->trim)
			free(par->trim);
		return (0);
	}
	store_textures(line, par);
	if (par->trim)
	{
		free(par->trim);
		par->trim = NULL;
	}
	free(par->subline);
	return (0);
}
