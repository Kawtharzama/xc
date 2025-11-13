/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:03:43 by tabuayya          #+#    #+#             */
/*   Updated: 2025/11/06 20:27:26 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_empty_line(char *line, t_parsing *par)
{
	int	i;

	i = 0;
	if (par->map_started == 0)
	{
		while (line[i])
		{
			if (!(line[i] == ' ') && !(line[i] >= 9 && line[i] <= 13))
				return (1);
			i++;
		}
	}
	else
	{
		while (line[i])
		{
			if (!(line[i] >= 9 && line[i] <= 13))
				return (1);
			i++;
		}
		par->map_ended = 1;
		return (1);
	}
	return (0);
}

int	check_args(char *s_line, t_parsing *par, char *line, char **split)
{
	char	**split_line;
	char	*trim;
	int		count;
	int		i;

	i = 0;
	count = 0;
	trim = NULL;
	split_line = ft_split(s_line, ',');
	if (!split_line)
		error_free(s_line, par, line, split, TRUE);
	while (split_line[i])
	{
		trim = ft_strtrim(split_line[i], " \a\b\f\n\r\t\v");
		if (ft_strcmp(trim, "") != 0)
			count++;
		free(trim);
		i++;
	}
	if (count != 3)
		par->valid = error_message("Wrong number of arguments\n", *par);
	free_split(split_line);
	return (0);
}

char	*get_substring(char *line, t_parsing *par)
{
	char	*trim;
	int		len;
	char	*substr;

	trim = ft_strtrim(line, " FNOSEAWC\a\b\f\n\r\t\v");
	if (!trim)
		error_free(line, par, trim, NULL, TRUE);
	len = ft_strlen(trim);
	substr = ft_substr(trim, 0, len);
	if (!substr)
		error_free(line, par, trim, NULL, TRUE);
	free(trim);
	return (substr);
}

int	keep_checking(char *line, t_parsing *par)
{
	if (!(line[0] == '\n'))
		par->valid = error_message("Empty line in map\n", *par);
	return (1);
}

int	check_all_args(t_parsing *par)
{
	if (!(par->valid_color_c && par->valid_color_f && par->text_ea
			&& par->text_no && par->text_so && par->text_we))
		par->valid = error_message("Arguments not complete\n", *par);
	return (0);
}
