/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:53:11 by tabuayya          #+#    #+#             */
/*   Updated: 2024/12/05 09:53:20 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	ft_puthex(unsigned int num, char c)
{
	char	*arr;
	int		len;

	arr = "0123456789abcdef";
	len = 0;
	if (num >= 16)
	{
		len += ft_puthex(num / 16, c);
		len += ft_puthex(num % 16, c);
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
