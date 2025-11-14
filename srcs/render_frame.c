/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabu-zee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:02:24 by kabu-zee          #+#    #+#             */
/*   Updated: 2025/11/13 19:02:25 by kabu-zee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				mlx_put_pixel(data->img, x, y, data->c_color);
			else
				mlx_put_pixel(data->img, x, y, data->f_color);
			x++;
		}
		y++;
	}
}

void	draw_texture_column(t_data *data, t_raycast *rc, int x)
{
	int		y;
	int		tex_y;
	t_color	color;

	rc->texture_step = 1.0 * data->texture_height[rc->tex_num]
		/ rc->line_height;
	rc->texture_pos = (rc->draw_pix_start - SCREEN_HEIGHT / 2 + rc->line_height
			/ 2) * rc->texture_step;
	y = rc->draw_pix_start;
	while (y <= rc->draw_pix_end)
	{
		tex_y = (int)rc->texture_pos;
		rc->texture_pos += rc->texture_step;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= data->texture_height[rc->tex_num])
			tex_y = data->texture_height[rc->tex_num] - 1;
		color = data->texture[rc->tex_num][data->texture_width[rc->tex_num]
			* tex_y + rc->texture_col];
		if (rc->wall_side == 1)
			color = shade_color_comp(color, 1.2);
		mlx_put_pixel(data->img, x, y, color);
		y++;
	}
}

void	render_frame(t_data *data)
{
	int			x;
	t_raycast	rc;

	clear_background(data);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		calculate_raycast(data, &rc, x);
		draw_texture_column(data, &rc, x);
		x++;
	}
}
