/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2ndutils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabu-zee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:02:37 by kabu-zee          #+#    #+#             */
/*   Updated: 2025/11/13 19:02:38 by kabu-zee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_compute_dist_and_height(t_data *data, t_raycast *rc)
{
	(void)data;
	if (rc->wall_side == 0)
		rc->perp_wall_dist = (rc->side_dist_x - rc->delta_dist_x);
	else
		rc->perp_wall_dist = (rc->side_dist_y - rc->delta_dist_y);
	rc->line_height = (int)(SCREEN_HEIGHT / rc->perp_wall_dist);
	rc->draw_pix_start = -rc->line_height / 2 + SCREEN_HEIGHT / 2;
	if (rc->draw_pix_start < 0)
		rc->draw_pix_start = 0;
	rc->draw_pix_end = rc->line_height / 2 + SCREEN_HEIGHT / 2;
	if (rc->draw_pix_end >= SCREEN_HEIGHT)
		rc->draw_pix_end = SCREEN_HEIGHT - 1;
}

void	ray_set_texnum(t_raycast *rc)
{
	if (rc->wall_side == 0)
	{
		if (rc->step_x > 0)
			rc->tex_num = 2;
		else
			rc->tex_num = 3;
	}
	else
	{
		if (rc->step_y > 0)
			rc->tex_num = 1;
		else
			rc->tex_num = 0;
	}
}

void	ray_compute_hit_and_texcol(t_data *data, t_raycast *rc)
{
	t_player	*p;
	double		tmp;

	p = &data->player;
	if (rc->wall_side == 0)
		tmp = p->pos_y + rc->perp_wall_dist * rc->ray_vector_y;
	else
		tmp = p->pos_x + rc->perp_wall_dist * rc->ray_vector_x;
	rc->hit_wall = tmp - floor(tmp);
	rc->texture_col = (int)(rc->hit_wall * data->texture_width[rc->tex_num]);
	if (rc->wall_side == 0 && rc->ray_vector_x <= 0)
		rc->texture_col = data->texture_width[rc->tex_num] - rc->texture_col
			- 1;
	if (rc->wall_side == 1 && rc->ray_vector_y >= 0)
		rc->texture_col = data->texture_width[rc->tex_num] - rc->texture_col
			- 1;
}

void	ray_finalize(t_data *data, t_raycast *rc)
{
	ray_compute_dist_and_height(data, rc);
	ray_set_texnum(rc);
	ray_compute_hit_and_texcol(data, rc);
}

void	calculate_raycast(t_data *data, t_raycast *rc, int x)
{
	ray_pos_dir(data, rc, x);
	ray_delta_and_sideinit(data, rc);
	ray_dda(data, rc);
	ray_finalize(data, rc);
}
