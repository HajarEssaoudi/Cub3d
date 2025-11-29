/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatim <hqannouc@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:20:29 by hes-saou          #+#    #+#             */
/*   Updated: 2025/11/23 17:11:06 by hatim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../parsing/parsing.h"
# include "./minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>

# define FOV 80
# define W 119
# define S 115
# define A 97
# define D 100
# define M 109
# define ESC 65307
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define WINDOW_HEIGHT 700
# define WINDOW_WIDTH 1200
# define PI 3.1415926535
# define MOVE_SPEED 0.05
# define ROT_SPEED 6.0

typedef enum e_dir
{
	NO,
	SO,
	EA,
	WE
}	t_dir;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_texture
{
	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_player
{
	double	x;
	double	y;
	double	angle;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	int			f_color;
	int			c_color;
	t_img_data	*img_data;
	t_player	player;
	t_texture	textures[4];
	t_scene		scene;
	t_keys		*keys;
}	t_game;

typedef struct s_ray_tex
{
	int		x;
	int		y;
	double	step;
	double	pos;
}	t_ray_tex;

typedef struct s_ray
{
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			window_x;
	int			side;
	double		delta_x;
	double		delta_y;
	double		angle;
	double		wall_x;
	double		wall_height;
	t_ray_tex	*tex;
	t_dir		wall_dir;
}	t_ray;

/* Rendering */
void	draw_ray(t_game *game, double r_angle, int x);
void	draw_3d_fov(t_game *game);
void	render_window(t_game *game);
void	draw_mini_map(t_game *game);
void	init_ray(t_game *game, double r_angle, t_ray *ray, int x);
double	count_dist(t_game *game, t_ray *ray);
void	init_textures(t_game *game);
void	get_wall_dir(t_ray *ray);
void	sample_texture(t_game *game, t_ray *ray, t_texture texture);

/* Movement */
void	move_player(t_game *game, double *x, double *y);

/* Maths utils */
double	deg_to_rad(double angle);

/* Mlx utils*/
int		handle_keypress(int keycode, t_game *game);
int		handle_keyrelease(int keycode, t_game *game);
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);

/*Exit game*/
int		handle_close_button(t_game *game);
void	free_game(t_game *game);

void	init_game(t_game *game, t_scene *scene);
void	parse_scene(t_scene *scene, char *file_path);

#endif