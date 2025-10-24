/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:20:29 by hes-saou          #+#    #+#             */
/*   Updated: 2025/10/24 22:21:37 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../parsing/parsing.h"
# include "./minilibx-linux/mlx.h"
# include <math.h>
# define FOV 50
# define W 119
# define S 115
# define A 97
# define D 100
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define PI 3.1415926535

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img_data;

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
	t_scene		scene;
}	t_game;

void	draw_ray(t_game *game, double r_angle, int x);
void	render_window(t_scene *scene, t_game *game);
void	draw_fov(t_game *game);
double	deg_to_rad(double angle);
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);

#endif