/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:20:29 by hes-saou          #+#    #+#             */
/*   Updated: 2025/10/31 01:28:46 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
#define CUBE_H

#include "../parsing/parsing.h"
#include "./minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

#define FOV 60
#define W 119
#define S 115
#define A 97
#define D 100
#define LEFT_ARROW 65361
#define RIGHT_ARROW 65363
#define PI 3.1415926535
#define TWO_PI (PI * 2)

typedef struct s_img_data
{
	void *img;
	char *addr;
	int bpp;
	int line_length;
	int endian;
}	t_img_data;

typedef struct s_player
{
	double x;
	double y;
	double angle;
}	t_player;

typedef struct s_game
{
	void *mlx;
	void *win;
	int win_width;
	int win_height;
	int f_color;
	int c_color;
	t_img_data *img_data;
	t_player player;
	t_scene scene;
}	t_game;

typedef struct s_ray
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	delta_x;
	double	delta_y;
	double	side_dx;
	double	side_dy;
	int		is_hit;
	char	wall_dir;
}	t_ray;

/* Rendering */
void	draw_ray(t_game *game, double r_angle, int x);
void	draw_3d_fov(t_game *game);
void	render_window(t_game *game);
void	draw_mini_map(t_game *game);
void init_ray(t_game *game, double r_angle, t_ray *ray);
double	count_dist(t_game *game, double r_angle, t_ray *ray);

/* Maths utils */
double deg_to_rad(double angle);

/* Mlx utils*/
void my_mlx_pixel_put(t_img_data *data, int x, int y, int color);

/*Exit game*/
int handle_close_button(t_game *game);

#endif