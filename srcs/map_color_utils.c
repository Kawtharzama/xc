/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_color_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabu-zee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:01:32 by kabu-zee          #+#    #+#             */
/*   Updated: 2025/11/13 19:01:34 by kabu-zee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color	shade_color_comp(t_color color, double factor)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 24) & 0xFF;
	g = (color >> 16) & 0xFF;
	b = (color >> 8) & 0xFF;
	r = (int)((double)r / factor);
	g = (int)((double)g / factor);
	b = (int)((double)b / factor);
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

t_color	color_from_rgb(int r, int g, int b)
{
	t_color	c;

	c = 0;
	c |= (t_color)(r << 24);
	c |= (t_color)(g << 16);
	c |= (t_color)(b << 8);
	c |= (t_color)0xFF;
	return (c);
}
