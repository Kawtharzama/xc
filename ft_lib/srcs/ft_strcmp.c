/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:47:19 by tabuayya          #+#    #+#             */
/*   Updated: 2024/06/11 17:58:58 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s2[i] != '\0' && s1[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
int main()
{
	char	a[] = "tasnim";
	char	b[] = "TASNIM";

	printf("%i", ft_strcmp(a,b));

	return (0);
}
*/
