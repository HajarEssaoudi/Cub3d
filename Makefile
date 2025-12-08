NAME = cub3d

LIBFT = mandatory/includes/libft/libft.a
MLX_DIR = /usr/include/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

SRCS = mandatory/parsing/scene_utils.c mandatory/parsing/check_utils.c mandatory/parsing/config_pars.c \
       mandatory/parsing/error_handle.c mandatory/parsing/map_pars.c mandatory/parsing/map_utils.c mandatory/parsing/file_utils.c \
       mandatory/render/ray_cast.c mandatory/render/window.c mandatory/render/ray_utils.c mandatory/render/keyboard_utils.c \
	   mandatory/render/textures.c mandatory/render/texture_init.c \
	   mandatory/exit_game/exit_game.c \
       mandatory/includes/gnl/get_next_line.c mandatory/includes/gnl/get_next_line_utils.c \
       mandatory/includes/garbage_collector/stdgc.c \
       mandatory/main_utils.c mandatory/main.c \

BONUS_SRCS = bonus/parsing/scene_utils_bonus.c bonus/parsing/check_utils_bonus.c \
			 bonus/parsing/config_pars_bonus.c bonus/parsing/error_handle_bonus.c \
			 bonus/parsing/map_pars_bonus.c bonus/parsing/map_utils_bonus.c \
			 bonus/parsing/file_utils_bonus.c \
			 bonus/render/ray_cast_bonus.c bonus/render/window_bonus.c \
			 bonus/render/ray_utils_bonus.c bonus/render/keyboard_utils_bonus.c \
	         bonus/render/textures_bonus.c bonus/render/texture_init_bonus.c \
	         bonus/exit_game/exit_game_bonus.c \
			 bonus/includes/gnl/get_next_line.c bonus/includes/gnl/get_next_line_utils.c \
			 bonus/includes/garbage_collector/stdgc_bonus.c \
			 bonus/mini_map_bonus.c bonus/mini_map_border.c \
			 bonus/main_utils_bonus.c bonus/main_bonus.c \

HEADERS = includes/cube.h parsing/parsing.h \
		  bonus/parsing/parsing_bonus.h bonus/includes/cube_bonus.h \
		  includes/garbage_collector/stdgc.h bonus/includes/garbage_collector/stdgc_bonus.h \

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I$(MLX_DIR) -Iincludes/libft -Iincludes/gnl -Iincludes

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	make -C includes/libft

$(MLX):
	make -C $(MLX_DIR)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) \
	-L$(MLX_DIR) -lmlx -lXext -lX11 -lm -o $(NAME)

$(NAME)_bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) \
	-L$(MLX_DIR) -lmlx -lXext -lX11 -lm -o $(NAME)_bonus

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	make -C includes/libft clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME)_bonus
	make -C includes/libft fclean

bonus: $(LIBFT) $(MLX) $(NAME)_bonus

re: fclean all

.PHONY: all clean fclean re bonus
