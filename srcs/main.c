/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasnimsamer <tasnimsamer@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:34:37 by tabuayya          #+#    #+#             */
/*   Updated: 2025/11/13 19:01:21 by kabu-zee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->f_color = color_from_rgb(data->parse.f_col[0], data->parse.f_col[1],
			data->parse.f_col[2]);
	data->c_color = color_from_rgb(data->parse.c_col[0], data->parse.c_col[1],
			data->parse.c_col[2]);
	data->curr_time = 0.0;
	data->prev_Time = 0.0;
	data->frameTime = 0.0;
	init_map_n_player(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(data));
	if (argc == 1)
		error("No map file\n");
	if (argc != 2)
		error("Too many arguments\n");
	parsing(argv, &data.parse);
	if (!data.parse.valid)
	{
		free_textures_paths_and_map(&data); // check this
		return (0);
	}
	init_data(&data);
	data.mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D", false);
	if (!data.mlx)
	{
		free_exit(&data, "can't initiate mlx\n", FALSE, TRUE);
		// free_textures_paths_and_map(&data);
		// error_free(NULL, &data.parse, data.parse.trim, data.parse.map, 1);
	} // check error
	data.img = mlx_new_image(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!data.img)
	{
		free_exit(&data, "Image allocation failed\n", TRUE, TRUE);
		// free_textures_paths_and_map(&data);
		// error_free(NULL, &data.parse, data.parse.trim, data.parse.map, 0);
		// mlx_terminate(data.mlx);
		// error("Image allocation failed\n");
	} // check erroe
	load_textures_from_files(&data);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	mlx_close_hook(data.mlx, close_program, &data);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_loop(data.mlx);
	mlx_delete_image(data.mlx, data.img);
	mlx_terminate(data.mlx);
	error_free(NULL, &data.parse, data.parse.trim, data.parse.map, FALSE);
	//    printf("end of program\n");
	return (0);
}
