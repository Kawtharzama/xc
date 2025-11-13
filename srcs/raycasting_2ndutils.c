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
		rc->perpWallDist = (rc->sideDistX - rc->deltaDistX);
	else
		rc->perpWallDist = (rc->sideDistY - rc->deltaDistY);
	rc->lineHeight = (int)(SCREEN_HEIGHT / rc->perpWallDist);
	rc->draw_pix_start = -rc->lineHeight / 2 + SCREEN_HEIGHT / 2;
	if (rc->draw_pix_start < 0)
		rc->draw_pix_start = 0;
	rc->draw_pix_end = rc->lineHeight / 2 + SCREEN_HEIGHT / 2;
	if (rc->draw_pix_end >= SCREEN_HEIGHT)
		rc->draw_pix_end = SCREEN_HEIGHT - 1;
}

void	ray_set_texnum(t_raycast *rc)
{
	if (rc->wall_side == 0)
	{
		if (rc->stepX > 0)
			rc->texNum = 2;
		else
			rc->texNum = 3;
	}
	else
	{
		if (rc->stepY > 0)
			rc->texNum = 1;
		else
			rc->texNum = 0;
	}
}

void	ray_compute_hit_and_texcol(t_data *data, t_raycast *rc)
{
	t_player	*p;
	double		tmp;

	p = &data->player;
	if (rc->wall_side == 0)
		tmp = p->posY + rc->perpWallDist * rc->rayVectorY;
	else
		tmp = p->posX + rc->perpWallDist * rc->rayVectorX;
	rc->hit_wall = tmp - floor(tmp);
	rc->texture_col = (int)(rc->hit_wall * data->texture_width[rc->texNum]);
	if (rc->wall_side == 0 && rc->rayVectorX <= 0)
		rc->texture_col = data->texture_width[rc->texNum] - rc->texture_col - 1;
	if (rc->wall_side == 1 && rc->rayVectorY >= 0)
		rc->texture_col = data->texture_width[rc->texNum] - rc->texture_col - 1;
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
