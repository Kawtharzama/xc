/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:46:02 by tabuayya          #+#    #+#             */
/*   Updated: 2025/11/06 20:25:25 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_id(char *line, t_parsing *par)
{
	int		i;
	char	*trim_line;

	if (!line)
		return (0);
	trim_line = ft_strtrim(line, " \a\b\f\n\r\t\v");
	if (!trim_line)
		error_free(line, par, NULL, NULL, TRUE);
	i = 0;
	while (trim_line[i])
	{
		if (trim_line[i] == ' ' || trim_line[i] == '\t')
			break ;
		i++;
	}
	par->id = ft_substr(trim_line, 0, i);
	if (!par->id)
		error_free(line, par, trim_line, NULL, TRUE);
	free(trim_line);
	return (0);
}

int	categorize(char *line, t_parsing *par)
{
	if (!skip_empty_line(line, par))
	{
		if (par->map_started == 0)
			return (1);
	}
	get_id(line, par);
	if ((ft_strcmp(par->id, "F") == 0) || (ft_strcmp(par->id, "C") == 0))
		check_color(line, par);
	else if ((ft_strcmp(par->id, "NO") == 0) || (ft_strcmp(par->id, "SO") == 0)
		|| (ft_strcmp(par->id, "EA") == 0) || (ft_strcmp(par->id, "WE") == 0))
		check_textures(line, par);
	else
		validate_map(line, par);
	if (par->id)
	{
		free(par->id);
		par->id = NULL;
	}
	return (0);
}

int	check_arguments(char *argv, t_parsing *par)
{
	char	*line;

	par->fd = open(argv, O_RDONLY);
	if (par->fd < 0)
		par->valid = error_message("No file to open\n", *par);
	line = get_next_line(par->fd);
	while (line && par->valid)
	{
		categorize(line, par);
		free(line);
		line = get_next_line(par->fd);
		if (!line)
			break ;
	}
	if (par->valid)
		parse_map(par, line);
	free(line);
	free_gnl(par->fd);
	close(par->fd);
	return (0);
}

int	check_extenstion(char *argv, t_parsing *par)
{
	size_t	len;

	len = ft_strlen(argv);
	if (argv[len - 4] == '.' && argv[len - 3] == 'c' && argv[len - 2] == 'u'
		&& argv[len - 1] == 'b' && argv[len] == '\0')
		par->valid_extenstion = 1;
	else
		par->valid = error_message("Wrong extenstion\n", *par);
	return (0);
}

int	parsing(char **argv, t_parsing *par)
{
	ft_bzero(par, sizeof(t_parsing));
	par->valid = 1;
	check_extenstion(argv[1], par);
	if (!par->valid)
		return (1);
	check_arguments(argv[1], par);
	return (0);
}
