/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:41:07 by tabuayya          #+#    #+#             */
/*   Updated: 2024/09/23 17:10:27 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static char	*copy_word(const char *start, int length)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((length + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < length)
	{
		word[i] = start[i];
		i++;
	}
	word[length] = '\0';
	return (word);
}

static void	free_memory(char **result, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(result[j]);
		j++;
	}
}

static char	*get_next_word(const char **s, char c)
{
	const char	*start;
	size_t		length;

	while (**s == c && **s)
		(*s)++;
	start = *s;
	length = 0;
	while (**s && **s != c)
	{
		length++;
		(*s)++;
	}
	if (length > 0)
		return (copy_word(start, length));
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	int		words;
	char	**result;
	int		i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < words)
	{
		result[i] = get_next_word(&s, c);
		if (!result[i++])
		{
			free_memory(result, i);
			free(result);
			return (NULL);
		}
	}
	result[i] = NULL;
	return (result);
}
