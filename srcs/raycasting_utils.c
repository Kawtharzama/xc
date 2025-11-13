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
	rc->cameraPlaneX = 2 * x;
	rc->cameraPlaneX /= (double)SCREEN_WIDTH;
	rc->cameraPlaneX -= 1;
	rc->rayVectorX = p->dirX + p->planeX * rc->cameraPlaneX;
	rc->rayVectorY = p->dirY + p->planeY * rc->cameraPlaneX;
	rc->map_cell_X = (int)p->posX;
	rc->map_cell_Y = (int)p->posY;
}

void	ray_init_x_side(t_player *p, t_raycast *rc)
{
	if (rc->rayVectorX < 0)
	{
		rc->stepX = -1;
		rc->sideDistX = (p->posX - rc->map_cell_X) * rc->deltaDistX;
	}
	else
	{
		rc->stepX = 1;
		rc->sideDistX = (rc->map_cell_X + 1.0 - p->posX) * rc->deltaDistX;
	}
}

void	ray_init_y_side(t_player *p, t_raycast *rc)
{
	if (rc->rayVectorY < 0)
	{
		rc->stepY = -1;
		rc->sideDistY = (p->posY - rc->map_cell_Y) * rc->deltaDistY;
	}
	else
	{
		rc->stepY = 1;
		rc->sideDistY = (rc->map_cell_Y + 1.0 - p->posY) * rc->deltaDistY;
	}
}

void	ray_delta_and_sideinit(t_data *data, t_raycast *rc)
{
	t_player	*p;

	p = &data->player;
	rc->deltaDistX = MAX_DIST;
	rc->deltaDistY = MAX_DIST;
	if (rc->rayVectorX != 0)
		rc->deltaDistX = fabs(1 / rc->rayVectorX);
	if (rc->rayVectorY != 0)
		rc->deltaDistY = fabs(1 / rc->rayVectorY);
	rc->hit = 0;
	ray_init_x_side(p, rc);
	ray_init_y_side(p, rc);
}

void	ray_dda(t_data *data, t_raycast *rc)
{
	while (rc->hit == 0)
	{
		if (rc->sideDistX < rc->sideDistY)
		{
			rc->sideDistX += rc->deltaDistX;
			rc->map_cell_X += rc->stepX;
			rc->wall_side = 0;
		}
		else
		{
			rc->sideDistY += rc->deltaDistY;
			rc->map_cell_Y += rc->stepY;
			rc->wall_side = 1;
		}
		if (data->gameMap[rc->map_cell_Y][rc->map_cell_X] > 0)
			rc->hit = 1;
	}
}
