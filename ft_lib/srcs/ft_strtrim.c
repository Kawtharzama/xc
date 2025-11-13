/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:59:18 by tabuayya          #+#    #+#             */
/*   Updated: 2025/10/10 15:58:05 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	from_start(char *s1, char *set)
{
	int	i;
	int	start;

	start = 0;
	while (s1[start])
	{
		i = 0;
		while (set[i])
		{
			if (s1[start] == set[i])
				break ;
			i++;
		}
		if (set[i] == '\0')
			break ;
		start++;
	}
	return (start);
}

int	from_end(char *s1, char *set)
{
	int	i;
	int	end;

	end = ft_strlen(s1) - 1;
	while (end >= 0)
	{
		i = 0;
		while (set[i])
		{
			if (s1[end] == set[i])
				break ;
			i++;
		}
		if (set[i] == '\0')
			break ;
		end--;
	}
	return (end);
}

char	*new_string(char *s1, int start, int end)
{
	int		i;
	char	*new;

	if (start > end)
		return (ft_strdup(""));
	new = malloc((end - start + 2) * sizeof(char));
	i = 0;
	if (!new)
		return (NULL);
	while (start <= end)
	{
		new[i] = s1[start];
		start++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	char	*new;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = from_start((char *)s1, (char *)set);
	end = from_end((char *)s1, (char *)set);
	new = new_string((char *)s1, start, end);
	if (!new)
		return (NULL);
	return (new);
}
