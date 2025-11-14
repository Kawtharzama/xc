/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabu-zee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:01:11 by kabu-zee          #+#    #+#             */
/*   Updated: 2025/11/13 19:01:12 by kabu-zee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loop_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	handle_movement(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->mlx);
		free_exit(data, NULL, TRUE);
	}
	render_frame(data);
}

void	close_program(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_close_window(data->mlx);
	free_exit(data, NULL, TRUE);
}

void	load_texture_pixels(t_data *data, mlx_texture_t *temp, int i)
{
	t_pixel	pixel;

	memset(&pixel, 0, sizeof(pixel));
	pixel.y = 0;
	while (pixel.y < temp->height)
	{
		pixel.x = 0;
		while (pixel.x < temp->width)
		{
			pixel.src_index = (pixel.y * (int)temp->width + pixel.x) * 4;
			pixel.r = temp->pixels[pixel.src_index];
			pixel.g = temp->pixels[pixel.src_index + 1];
			pixel.b = temp->pixels[pixel.src_index + 2];
			data->texture[i][pixel.y * data->texture_width[i]
				+ pixel.x] = color_from_rgb((int)pixel.r, (int)pixel.g,
					(int)pixel.b);
			pixel.x++;
		}
		pixel.y++;
	}
}

void	load_single_texture(t_data *data, const char *path, int idx)
{
	mlx_texture_t	*temp_texture;
	int				width;
	int				height;

	temp_texture = mlx_load_png(path);
	if (!temp_texture)
		free_exit(data, "Could not load texture file\n", TRUE);
	width = temp_texture->width;
	height = temp_texture->height;
	data->texture_width[idx] = width;
	data->texture_height[idx] = height;
	data->texture[idx] = malloc(sizeof(uint32_t) * width * height);
	if (!data->texture[idx])
	{
		mlx_delete_texture(temp_texture);
		free_exit(data, "Failed to allocate texture memory\n", TRUE);
	}
	load_texture_pixels(data, temp_texture, idx);
	mlx_delete_texture(temp_texture);
}

void	load_textures_from_files(t_data *data)
{
	const char	*paths[NUM_TEXTURES];
	int			i;

	paths[0] = data->parse.no_path;
	paths[1] = data->parse.so_path;
	paths[2] = data->parse.ea_path;
	paths[3] = data->parse.we_path;
	i = 0;
	while (i < NUM_TEXTURES)
	{
		load_single_texture(data, paths[i], i);
		i++;
	}
}
