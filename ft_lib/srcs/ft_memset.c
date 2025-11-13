/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:47:47 by tabuayya          #+#    #+#             */
/*   Updated: 2024/09/03 17:21:12 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*new;

	new = (unsigned char *)s;
	while (n--)
	{
		*new = (unsigned char)c;
		new ++;
	}
	return (s);
}
