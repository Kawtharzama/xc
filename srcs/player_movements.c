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
		if (data->game_map[(int)p->pos_y][(int)(p->pos_x + p->dir_x
				* check_dist)] == 0)
			p->pos_x += p->dir_x * moveSpeed;
		if (data->game_map[(int)(p->pos_y + p->dir_y
				* check_dist)][(int)p->pos_x] == 0)
			p->pos_y += p->dir_y * moveSpeed;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		if (data->game_map[(int)p->pos_y][(int)(p->pos_x - p->dir_x
				* check_dist)] == 0)
			p->pos_x -= p->dir_x * moveSpeed;
		if (data->game_map[(int)(p->pos_y - p->dir_y
				* check_dist)][(int)p->pos_x] == 0)
			p->pos_y -= p->dir_y * moveSpeed;
	}
}

static void	move_strafe(t_data *data, t_player *p, double moveSpeed,
		double check_dist)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		if (data->game_map[(int)p->pos_y][(int)(p->pos_x + p->plane_x
				* check_dist)] == 0)
			p->pos_x += p->plane_x * moveSpeed;
		if (data->game_map[(int)(p->pos_y + p->plane_y
				* check_dist)][(int)p->pos_x] == 0)
			p->pos_y += p->plane_y * moveSpeed;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		if (data->game_map[(int)p->pos_y][(int)(p->pos_x - p->plane_x
				* check_dist)] == 0)
			p->pos_x -= p->plane_x * moveSpeed;
		if (data->game_map[(int)(p->pos_y - p->plane_y
				* check_dist)][(int)p->pos_x] == 0)
			p->pos_y -= p->plane_y * moveSpeed;
	}
}

static void	rotate_right(t_player *p, double rotSpeed)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = p->dir_x;
	p->dir_x = p->dir_x * cos(rotSpeed) - p->dir_y * sin(rotSpeed);
	p->dir_y = oldDirX * sin(rotSpeed) + p->dir_y * cos(rotSpeed);
	oldPlaneX = p->plane_x;
	p->plane_x = p->plane_x * cos(rotSpeed) - p->plane_y * sin(rotSpeed);
	p->plane_y = oldPlaneX * sin(rotSpeed) + p->plane_y * cos(rotSpeed);
}

static void	rotate_left(t_player *p, double rotSpeed)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = p->dir_x;
	p->dir_x = p->dir_x * cos(-rotSpeed) - p->dir_y * sin(-rotSpeed);
	p->dir_y = oldDirX * sin(-rotSpeed) + p->dir_y * cos(-rotSpeed);
	oldPlaneX = p->plane_x;
	p->plane_x = p->plane_x * cos(-rotSpeed) - p->plane_y * sin(-rotSpeed);
	p->plane_y = oldPlaneX * sin(-rotSpeed) + p->plane_y * cos(-rotSpeed);
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
