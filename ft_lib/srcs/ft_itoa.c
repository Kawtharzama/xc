/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 13:47:54 by tabuayya          #+#    #+#             */
/*   Updated: 2024/09/21 16:04:36 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

int	num_digits(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*new_array(long new, char *nres, int j)
{
	int	n;

	while (new > 0)
	{
		n = new % 10;
		nres[j] = n + '0';
		new /= 10;
		j--;
	}
	return (nres);
}

char	*ft_itoa(int n)
{
	int		i;
	long	new;
	char	*res;

	new = n;
	i = num_digits(n);
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	if (new == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	if (new < 0)
	{
		res[0] = '-';
		new *= -1;
	}
	new_array(new, res, i - 1);
	res[i] = '\0';
	return (res);
}
