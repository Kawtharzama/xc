/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasnimsamer <tasnimsamer@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:39:32 by tabuayya          #+#    #+#             */
/*   Updated: 2025/11/07 00:14:56 by tasnimsamer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../ft_lib/includes/libft.h"
# include "MLX42/MLX42.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define SCREEN_WIDTH 1500
# define SCREEN_HEIGHT 1000
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define NUM_TEXTURES 4
# define FALSE 0
# define TRUE 1
# define MAX_DIST 1e30
# define MOVESPEED 0.05
# define ROTSPEED 0.03

typedef uint32_t	t_color;

typedef struct s_parsing
{
	int				map_started;
	int				text_no;
	int				text_so;
	int				text_ea;
	int				text_we;
	int				valid_color_f;
	int				valid_color_c;
	int				valid_extenstion;
	int				valid;
	int				fd;
	int				map_r;
	int				map_height;
	int				longest_line;
	int				n_char;
	int				play_x;
	int				play_y;
	int				map_ended;
	char			*id;
	char			**map;
	char			**cp_map;
	char			**split_line;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*args;
	char			*trim;
	char			*subline;
	int				col[3];
	int				f_col[3];
	int				c_col[3];
}					t_parsing;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}					t_player;

typedef struct s_raycast
{
	double			camera_plane_x;
	double			ray_vector_x;
	double			ray_vector_y;
	int				map_cell_x;
	int				map_cell_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				wall_side;
	int				line_height;
	int				draw_pix_start;
	int				draw_pix_end;
	int				tex_num;
	double			hit_wall;
	int				texture_col;
	double			texture_step;
	double			texture_pos;
}					t_raycast;

typedef struct s_data
{
	t_parsing		parse;
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_player		player;
	double			curr_time;
	double			prev_time;
	double			frametime;
	int				**game_map;
	uint32_t		*texture[NUM_TEXTURES];
	int				texture_width[NUM_TEXTURES];
	int				texture_height[NUM_TEXTURES];
	t_color			f_color;
	t_color			c_color;
}					t_data;

typedef struct s_pixel
{
	unsigned int	x;
	unsigned int	y;
	int				src_index;
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
}					t_pixel;

/* ---------------------------- Errors and Free ---------------------------- */
int					error_message(char *str, t_parsing parse);
void				error(char *str);
void				error_free(char *str, t_parsing *par, char *trim,
						char **split);
void				free_split(char **split_line);
void				free_gnl(int fd);

/* ------------------------------- Parsing -------------------------------- */
int					parsing(char **argv, t_parsing *par);
void				inti_parse(t_parsing *parse);
int					check_extenstion(char *argv, t_parsing *parse);
int					check_arguments(char *argv, t_parsing *parse);
int					categorize(char *line, t_parsing *parse);
char				*get_id(char *line, t_parsing *parse);

/* ---------------------------- Parsing Colors ----------------------------- */
int					check_color(char *line, t_parsing *parse);
int					validate_color(char *s_line, t_parsing *par, char *line);
int					check_number(char *trim, t_parsing *parse);
int					check_commas(char *line, t_parsing *parse);

/* ----------------------------- Parsing Utils ----------------------------- */
int					check_args(char *s_line, t_parsing *par, char *line,
						char **split);
int					skip_empty_line(char *line, t_parsing *par);
char				*get_substring(char *line, t_parsing *par);
int					check_all_args(t_parsing *parse);
int					keep_checking(char *line, t_parsing *par);

/* --------------------------- Parsing Textures ---------------------------- */
int					check_textures(char *line, t_parsing *parse);
int					check_path(char *path, t_parsing *parse);
int					check_args_text(char *line, t_parsing *par);
int					check_repeats(t_parsing *parse);

/* ----------------------------- Storing Map ------------------------------- */
int					validate_map(char *line, t_parsing *par);
void				print_map(char **map);
int					store_map(char *line, t_parsing *par);

/* ----------------------------- Parsing Maps ------------------------------ */
int					parse_map(t_parsing *par, char *line);

/* ---------------------------- Main.c Prototypes -------------------------- */
void				init_player(t_data *data, int x, int y);
void				init_map_n_player(t_data *data);
void				calculate_raycast(t_data *data, t_raycast *rc, int x);
void				render_frame(t_data *data);
void				handle_movement(t_data *data);
void				load_textures_from_files(t_data *data);
void				init_data(t_data *data);
void				free_textures_paths_and_map(t_data *data);

/* ---------------------------- Main.c Prototypes -------------------------- */
void				init_player(t_data *data, int x, int y);
void				init_map_n_player(t_data *data);
void				calculate_raycast(t_data *data, t_raycast *rc, int x);
void				render_frame(t_data *data);
void				handle_movement(t_data *data);
void				load_textures_from_files(t_data *data);
void				init_data(t_data *data);
void				free_textures_paths_and_map(t_data *data);
void				key_hook(mlx_key_data_t keydata, void *param);

t_color				color_from_rgb(int r, int g, int b);
t_color				shade_color_comp(t_color color, double factor);

void				loop_hook(void *param);
void				ray_compute_dist_and_height(t_data *data, t_raycast *rc);
void				ray_set_texnum(t_raycast *rc);
void				ray_compute_hit_and_texcol(t_data *data, t_raycast *rc);
void				ray_finalize(t_data *data, t_raycast *rc);
void				calculate_raycast(t_data *data, t_raycast *rc, int x);

void				ray_pos_dir(t_data *data, t_raycast *rc, int x);
void				ray_init_x_side(t_player *p, t_raycast *rc);
void				ray_init_y_side(t_player *p, t_raycast *rc);
void				ray_delta_and_sideinit(t_data *data, t_raycast *rc);
void				ray_dda(t_data *data, t_raycast *rc);

void				free_textures_paths_and_map(t_data *data);
void				free_exit(t_data *data, char *str, bool mlx_ter);
void				free_map(t_data *data);

void				close_program(void *param);
void				update_time_and_speeds(t_data *data, double *moveSpeed,
						double *rotSpeed);

void				move_forward_backward(t_data *data, t_player *p,
						double moveSpeed, double check_dist);
void				move_strafe(t_data *data, t_player *p, double moveSpeed,
						double check_dist);
void				rotate_right(t_player *p, double rotSpeed);
void				rotate_left(t_player *p, double rotSpeed);

void				handle_movement(t_data *data);

#endif
