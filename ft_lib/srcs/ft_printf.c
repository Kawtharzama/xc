/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:51:24 by tabuayya          #+#    #+#             */
/*   Updated: 2024/12/05 09:51:28 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

static int	check_format(char c, va_list args)
{
	int	length;

	length = 0;
	if (c == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (c == 's')
		length += ft_putstr(va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		length += ft_putnbr(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		length += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == 'u')
		length += ft_unsigned_putnbr(va_arg(args, unsigned int));
	else if (c == 'p')
		length += ft_putptr(va_arg(args, unsigned long int), c);
	else if (c == '%')
		length += ft_putchar('%');
	return (length);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
			len += check_format(s[++i], args);
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (len);
}
