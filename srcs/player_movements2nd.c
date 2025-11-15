/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements2nd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabu-zee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:02:14 by kabu-zee          #+#    #+#             */
/*   Updated: 2025/11/13 19:02:15 by kabu-zee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_time_and_speeds(t_data *data, double *moveSpeed,
		double *rotSpeed)
{
	*moveSpeed = MOVESPEED;
	*rotSpeed = ROTSPEED;
	data->prev_time = data->curr_time;
	data->curr_time = mlx_get_time();
	data->frametime = data->curr_time - data->prev_time;
	*moveSpeed *= data->frametime * 60.0;
	*rotSpeed *= data->frametime * 60.0;
}
