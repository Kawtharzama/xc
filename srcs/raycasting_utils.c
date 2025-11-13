/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabu-zee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:02:44 by kabu-zee          #+#    #+#             */
/*   Updated: 2025/11/13 19:02:45 by kabu-zee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_pos_dir(t_data *data, t_raycast *rc, int x)
{
	t_player	*p;

	p = &data->player;
	rc->camera_plane_x = 2 * x;
	rc->camera_plane_x /= (double)SCREEN_WIDTH;
	rc->camera_plane_x -= 1;
	rc->ray_vector_x = p->dir_x + p->plane_x * rc->camera_plane_x;
	rc->ray_vector_y = p->dir_y + p->plane_y * rc->camera_plane_x;
	rc->map_cell_x = (int)p->pos_x;
	rc->map_cell_y = (int)p->pos_y;
}

void	ray_init_x_side(t_player *p, t_raycast *rc)
{
	if (rc->ray_vector_x < 0)
	{
		rc->step_x = -1;
		rc->side_dist_x = (p->pos_x - rc->map_cell_x) * rc->delta_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist_x = (rc->map_cell_x + 1.0 - p->pos_x) * rc->delta_dist_x;
	}
}

void	ray_init_y_side(t_player *p, t_raycast *rc)
{
	if (rc->ray_vector_y < 0)
	{
		rc->step_y = -1;
		rc->side_dist_y = (p->pos_y - rc->map_cell_y) * rc->delta_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist_y = (rc->map_cell_y + 1.0 - p->pos_y) * rc->delta_dist_y;
	}
}

void	ray_delta_and_sideinit(t_data *data, t_raycast *rc)
{
	t_player	*p;

	p = &data->player;
	rc->delta_dist_x = MAX_DIST;
	rc->delta_dist_y = MAX_DIST;
	if (rc->ray_vector_x != 0)
		rc->delta_dist_x = fabs(1 / rc->ray_vector_x);
	if (rc->ray_vector_y != 0)
		rc->delta_dist_y = fabs(1 / rc->ray_vector_y);
	rc->hit = 0;
	ray_init_x_side(p, rc);
	ray_init_y_side(p, rc);
}

void	ray_dda(t_data *data, t_raycast *rc)
{
	while (rc->hit == 0)
	{
		if (rc->side_dist_x < rc->side_dist_y)
		{
			rc->side_dist_x += rc->delta_dist_x;
			rc->map_cell_x += rc->step_x;
			rc->wall_side = 0;
		}
		else
		{
			rc->side_dist_y += rc->delta_dist_y;
			rc->map_cell_y += rc->step_y;
			rc->wall_side = 1;
		}
		if (data->game_map[rc->map_cell_y][rc->map_cell_x] > 0)
			rc->hit = 1;
	}
}
