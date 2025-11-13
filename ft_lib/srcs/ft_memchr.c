/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:14:53 by tabuayya          #+#    #+#             */
/*   Updated: 2024/09/05 12:29:15 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new;

	new = (unsigned char *)s;
	while (n--)
	{
		if (*new == (unsigned char)c)
			return (new);
		new ++;
	}
	return (NULL);
}
