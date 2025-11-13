/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:48:51 by tabuayya          #+#    #+#             */
/*   Updated: 2025/10/10 15:29:31 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*snew;
	int		i;

	i = 0;
	snew = (char *)malloc(ft_strlen(s) + 1);
	if (!snew)
	{
		return (NULL);
	}
	while (s[i])
	{
		snew[i] = s[i];
		i++;
	}
	snew[i] = '\0';
	return (snew);
}
