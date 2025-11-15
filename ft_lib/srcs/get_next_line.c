/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:19:35 by tabuayya          #+#    #+#             */
/*   Updated: 2025/11/02 17:53:52 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_gnl(char **line)
{
	if (*line != NULL)
	{
		free(*line);
		*line = NULL;
		return (NULL);
	}
	return (NULL);
}

char	*get_data(char **line)
{
	char	*buff;
	char	*result;
	int		location;

	if (*line == NULL)
		return (NULL);
	buff = *line;
	location = ft_strchr_gnl(buff, '\n');
	if (location == -1)
	{
		if (ft_strlen_gnl(buff) == 0)
			return (ft_free_gnl(line));
		result = ft_strdup_gnl(*line);
		ft_free_gnl(line);
		return (result);
	}
	result = ft_substr_gnl(buff, 0, location + 1);
	if (result == NULL)
		return (ft_free_gnl(line));
	*line = ft_substr_gnl(buff, location + 1, (ft_strlen_gnl(buff) - location));
	free(buff);
	return (result);
}

void	*manager_buffer(char **line, int *read_size, int fd)
{
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (ft_free_gnl(line));
	*read_size = read(fd, buff, BUFFER_SIZE);
	if (*read_size == -1)
	{
		free(buff);
		return (ft_free_gnl(line));
	}
	buff[*read_size] = 0;
	*line = ft_strjoin_gnl(*line, buff);
	free(buff);
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			read_size;
	static char	*line;

	read_size = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (line == NULL)
		line = ft_strdup_gnl("");
	while (read_size > 0)
	{
		if (ft_strchr_gnl(line, '\n') == -1)
		{
			manager_buffer(&line, &read_size, fd);
			if (line == NULL)
				return (ft_free_gnl(&line));
		}
		else
			return (get_data(&line));
	}
	return (get_data(&line));
}
