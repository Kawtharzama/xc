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

void	move_forward_backward(t_data *data, t_player *p, double moveSpeed,
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

void	move_strafe(t_data *data, t_player *p, double moveSpeed,
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

void	rotate_right(t_player *p, double rotSpeed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rotSpeed) - p->dir_y * sin(rotSpeed);
	p->dir_y = old_dir_x * sin(rotSpeed) + p->dir_y * cos(rotSpeed);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rotSpeed) - p->plane_y * sin(rotSpeed);
	p->plane_y = old_plane_x * sin(rotSpeed) + p->plane_y * cos(rotSpeed);
}

void	rotate_left(t_player *p, double rotSpeed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(-rotSpeed) - p->dir_y * sin(-rotSpeed);
	p->dir_y = old_dir_x * sin(-rotSpeed) + p->dir_y * cos(-rotSpeed);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(-rotSpeed) - p->plane_y * sin(-rotSpeed);
	p->plane_y = old_plane_x * sin(-rotSpeed) + p->plane_y * cos(-rotSpeed);
}

void	handle_movement(t_data *data)
{
	t_player	*p;
	double		move_speed;
	double		rot_speed;
	double		check_dist;

	p = &data->player;
	update_time_and_speeds(data, &move_speed, &rot_speed);
	check_dist = move_speed * 1.5;
	move_forward_backward(data, p, move_speed, check_dist);
	move_strafe(data, p, move_speed, check_dist);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_right(p, rot_speed);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_left(p, rot_speed);
}
