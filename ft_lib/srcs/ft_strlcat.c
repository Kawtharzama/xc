/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:14:27 by tabuayya          #+#    #+#             */
/*   Updated: 2024/09/11 12:37:44 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	i;
	size_t	dlen;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	dlen = i;
	if (size == 0 || size <= dlen)
		return (ft_strlen(src) + size);
	while (src[j] != '\0' && j < size - dlen - 1)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dlen + ft_strlen(src));
}
/*
int	main(void)
{
	char	a[11] = "a";

	printf("%zu", ft_strlcat(a, "lorem", 15));
}
*/
