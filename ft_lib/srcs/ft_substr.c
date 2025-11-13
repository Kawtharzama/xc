/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:02:42 by tabuayya          #+#    #+#             */
/*   Updated: 2025/01/29 19:19:45 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;
	size_t			j;

	j = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	i = start;
	while ((j < len) && s[i])
	{
		new[j] = s[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}
