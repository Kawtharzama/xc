/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:01:52 by tabuayya          #+#    #+#             */
/*   Updated: 2024/09/21 16:01:56 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*snew;
	unsigned char	*dnew;
	int				i;

	i = 0;
	snew = (unsigned char *)src;
	dnew = (unsigned char *)dest;
	if (snew == NULL && dnew == NULL)
		return (NULL);
	if (snew > dnew)
	{
		return (ft_memcpy(dest, src, n));
	}
	else if (dnew > snew)
	{
		i = n;
		while (i-- > 0)
		{
			dnew[i] = snew[i];
		}
		return (dest);
	}
	return (dest);
}
