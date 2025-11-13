/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:54:49 by tabuayya          #+#    #+#             */
/*   Updated: 2024/12/05 09:54:53 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

static int	ft_findnumlen(unsigned int c)
{
	long	nb;
	int		counter;

	nb = c;
	if (nb == 0)
		return (1);
	counter = 0;
	while (nb > 0)
	{
		counter++;
		nb = nb / 10;
	}
	return (counter);
}

static char	*ft_uitoa(unsigned int n)
{
	size_t	numlen;
	long	nb;
	char	*result;

	nb = n;
	numlen = ft_findnumlen(n);
	result = (char *)malloc(numlen + 1);
	if (!result)
		return (0);
	result[numlen] = '\0';
	if (nb == 0)
		result[0] = '0';
	while (nb > 0)
	{
		result[numlen - 1] = (nb % 10) + '0';
		nb /= 10;
		numlen--;
	}
	return (result);
}

int	ft_unsigned_putnbr(unsigned int nbr)
{
	int		length;
	char	*num;

	length = 0;
	num = ft_uitoa(nbr);
	length = ft_putstr(num);
	free(num);
	return (length);
}
