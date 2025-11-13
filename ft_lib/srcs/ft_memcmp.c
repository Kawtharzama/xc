/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:31:10 by tabuayya          #+#    #+#             */
/*   Updated: 2024/09/05 15:14:53 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1new;
	const unsigned char	*s2new;

	s1new = (const unsigned char *)s1;
	s2new = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1new[i] != s2new[i])
			return (s1new[i] - s2new[i]);
		i++;
	}
	return (0);
}
