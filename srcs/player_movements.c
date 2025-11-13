/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabu-zee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:02:14 by kabu-zee          #+#    #+#             */
/*   Updated: 2025/11/13 19:02:15 by kabu-zee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_time_and_speeds(t_data *data, double *moveSpeed,
		double *rotSpeed)
{
	*moveSpeed = MOVESPEED;
	*rotSpeed = ROTSPEED;
	data->prev_Time = data->curr_time;
	data->curr_time = mlx_get_time();
	data->frameTime = data->curr_time - data->prev_Time;
	*moveSpeed *= data->frameTime * 60.0;
	*rotSpeed *= data->frameTime * 60.0;
}

static void	move_forward_backward(t_data *data, t_player *p, double moveSpeed,
		double check_dist)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		if (data->gameMap[(int)p->posY][(int)(p->posX + p->dirX
				* check_dist)] == 0)
			p->posX += p->dirX * moveSpeed;
		if (data->gameMap[(int)(p->posY + p->dirY
				* check_dist)][(int)p->posX] == 0)
			p->posY += p->dirY * moveSpeed;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		if (data->gameMap[(int)p->posY][(int)(p->posX - p->dirX
				* check_dist)] == 0)
			p->posX -= p->dirX * moveSpeed;
		if (data->gameMap[(int)(p->posY - p->dirY
				* check_dist)][(int)p->posX] == 0)
			p->posY -= p->dirY * moveSpeed;
	}
}

static void	move_strafe(t_data *data, t_player *p, double moveSpeed,
		double check_dist)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		if (data->gameMap[(int)p->posY][(int)(p->posX + p->planeX
				* check_dist)] == 0)
			p->posX += p->planeX * moveSpeed;
		if (data->gameMap[(int)(p->posY + p->planeY
				* check_dist)][(int)p->posX] == 0)
			p->posY += p->planeY * moveSpeed;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		if (data->gameMap[(int)p->posY][(int)(p->posX - p->planeX
				* check_dist)] == 0)
			p->posX -= p->planeX * moveSpeed;
		if (data->gameMap[(int)(p->posY - p->planeY
				* check_dist)][(int)p->posX] == 0)
			p->posY -= p->planeY * moveSpeed;
	}
}

static void	rotate_right(t_player *p, double rotSpeed)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = p->dirX;
	p->dirX = p->dirX * cos(rotSpeed) - p->dirY * sin(rotSpeed);
	p->dirY = oldDirX * sin(rotSpeed) + p->dirY * cos(rotSpeed);
	oldPlaneX = p->planeX;
	p->planeX = p->planeX * cos(rotSpeed) - p->planeY * sin(rotSpeed);
	p->planeY = oldPlaneX * sin(rotSpeed) + p->planeY * cos(rotSpeed);
}

static void	rotate_left(t_player *p, double rotSpeed)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = p->dirX;
	p->dirX = p->dirX * cos(-rotSpeed) - p->dirY * sin(-rotSpeed);
	p->dirY = oldDirX * sin(-rotSpeed) + p->dirY * cos(-rotSpeed);
	oldPlaneX = p->planeX;
	p->planeX = p->planeX * cos(-rotSpeed) - p->planeY * sin(-rotSpeed);
	p->planeY = oldPlaneX * sin(-rotSpeed) + p->planeY * cos(-rotSpeed);
}

void	handle_movement(t_data *data)
{
	t_player *p;
	double moveSpeed;
	double rotSpeed;
	double check_dist;

	p = &data->player;
	update_time_and_speeds(data, &moveSpeed, &rotSpeed);
	check_dist = moveSpeed * 1.5;
	move_forward_backward(data, p, moveSpeed, check_dist);
	move_strafe(data, p, moveSpeed, check_dist);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_right(p, rotSpeed);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_left(p, rotSpeed);
}
