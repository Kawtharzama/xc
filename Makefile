NAME = cub3D

CC = cc
MLXPATH = MLX42/build
MLX_DIR = MLX42
CFLAGS = -g -Wall -Wextra -Werror -I./ft_lib/includes -I./MLX42/include
SRCDIR = srcs
OBJDIR = obj
LIBPATH = ft_lib/

LIB = -L./ft_lib -lft -L./$(MLXPATH) -lmlx42 -ldl -lglfw -pthread -lm -lX11 -lXrandr -lXinerama -lXcursor

RM = rm -rf

SRCS = 	main.c\
		parsing.c\
		parsing_map.c\
		error_free.c\
		parsing_utils.c\
		parsing_colors.c\
		parsing_textures.c\
		storing_map.c\
		map.c\
		map_color_utils.c\
		raycasting_utils.c\
		raycasting_2ndutils.c\
		render_frame.c\
		free_helpers.c\
		load_texture.c\
		player.c\
		player_movements.c\

SRC  = $(addprefix $(SRCDIR)/, $(SRCS))

OBJ  = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

all: mlx42 $(NAME)

mlx42:
	cmake -B $(MLX_DIR)/build $(MLX_DIR)
	cmake --build $(MLX_DIR)/build -j4

$(NAME): $(OBJ)
	make -C $(LIBPATH)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	make clean -C $(LIBPATH)
	$(RM) $(OBJDIR)

fclean: clean
	make fclean -C $(LIBPATH)
	$(RM) $(MLXPATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re mlx42
