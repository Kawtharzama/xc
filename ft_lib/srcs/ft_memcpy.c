/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:09:03 by tabuayya          #+#    #+#             */
/*   Updated: 2024/09/05 12:13:10 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*snew;
	unsigned char	*dnew;

	snew = (unsigned char *)src;
	dnew = (unsigned char *)dest;
	if (!dest && !src)
		return (0);
	while (n--)
	{
		*dnew = *snew;
		dnew++;
		snew++;
	}
	return (dest);
}
