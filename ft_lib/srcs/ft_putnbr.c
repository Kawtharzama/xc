/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:53:57 by tabuayya          #+#    #+#             */
/*   Updated: 2024/12/05 09:54:01 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	ft_putnbr(int n)
{
	char	*mynum;
	int		len;

	len = 0;
	mynum = (ft_itoa(n));
	if (!mynum)
	{
		len += 1;
		ft_putchar('0');
	}
	else
		len = ft_putstr(mynum);
	free(mynum);
	return (len);
}
