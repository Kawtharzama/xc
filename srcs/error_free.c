/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:42:39 by tabuayya          #+#    #+#             */
/*   Updated: 2025/11/06 20:22:46 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
}

void	free_split(char **split_line)
{
	int	i;

	i = 0;
	while (split_line[i])
	{
		free(split_line[i]);
		i++;
	}
	free(split_line);
}

int	error_message(char *str, t_parsing par)
{
	if (par.valid)
	{
		printf("Error\n");
		printf("%s", str);
	}
	return (0);
}

void	error(char *str)
{
	printf("Error\n");
	printf("%s", str);
	exit(1);
}

void	error_free(char *str, t_parsing *par, char *trim, char **split)
		// 4 vars
{
	if (par->no_path)
		free(par->no_path);
	if (par->we_path)
		free(par->we_path);
	if (par->ea_path)
		free(par->ea_path);
	if (par->so_path)
		free(par->so_path);
	if (str)
		free(str);
	if (par->id)
		free(par->id);
	if (trim)
		free(trim);
	if (split)
		free_split(split);
	if (par->trim)
		free(par->trim);
	free_gnl(par->fd);
	exit(1);
}
