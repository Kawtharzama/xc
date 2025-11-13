/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:12:17 by tabuayya          #+#    #+#             */
/*   Updated: 2024/09/11 12:36:59 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*snew;
	int		i;

	i = 0;
	snew = (char *)s;
	while (snew[i])
		i++;
	if ((char)c == '\0')
	{
		return (&snew[i]);
	}
	i--;
	while (snew[i] && i >= 0)
	{
		if (s[i] == (char)c)
			return (&snew[i]);
		else
			i--;
	}
	return (NULL);
}
