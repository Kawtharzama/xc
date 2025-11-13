/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:20:32 by tabuayya          #+#    #+#             */
/*   Updated: 2024/09/03 09:17:23 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s2[i] && s1[i] && i < n)
		i++;
	if (n == i)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
