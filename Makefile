NAME = cub3d

LIBFT = ./includes/libft/libft.a
MLX_DIR = /usr/include/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

SRCS = parsing/scene_utils.c parsing/check_utils.c parsing/config_pars.c \
       parsing/error_handle.c parsing/map_pars.c parsing/map_utils.c parsing/file_utils.c \
       render/ray_cast.c render/window.c render/mini_map.c\
	   exit_game/exit_game.c \
       includes/gnl/get_next_line.c includes/gnl/get_next_line_utils.c \
       includes/garbage_collector/stdgc.c \
       main.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I$(MLX_DIR) -Iincludes/libft -Iincludes/gnl -Iincludes

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	make -C includes/libft

$(MLX):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) \
	-L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C includes/libft clean

fclean: clean
	rm -f $(NAME)
	make -C includes/libft fclean

run: all clean
	clear ; ./$(NAME) maps/scene.cub

valgrind: all clean
	./$(NAME) maps/scene.cub

re: fclean all
