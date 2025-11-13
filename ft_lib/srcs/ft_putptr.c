/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:54:09 by tabuayya          #+#    #+#             */
/*   Updated: 2024/12/05 09:54:12 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

static int	ft_longputhex(unsigned long int num, char c)
{
	char	*arr;
	int		len;

	arr = "0123456789abcdef";
	len = 0;
	if (num >= 16)
	{
		len += ft_longputhex(num / 16, c);
		len += ft_longputhex(num % 16, c);
	}
	else
	{
		if (num <= 9)
			len += ft_putchar(arr[num]);
		else
		{
			if (c == 'X')
				len += ft_putchar(arr[num] - 32);
			else
				len += ft_putchar(arr[num]);
		}
	}
	return (len);
}

int	ft_putptr(unsigned long p, char c)
{
	int	i;

	i = 0;
	if (p == 0)
	{
		return (ft_putstr("(nil)"));
	}
	i += ft_putstr("0x");
	i += ft_longputhex(p, c);
	return (i);
}
