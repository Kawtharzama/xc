/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 07:37:46 by tabuayya          #+#    #+#             */
/*   Updated: 2024/09/11 14:30:23 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new;

	new = malloc((nmemb * size));
	if (!new)
	{
		return (NULL);
	}
	if (new == NULL)
		return (NULL);
	ft_bzero(new, nmemb * size);
	return (new);
}
