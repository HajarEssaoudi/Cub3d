/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:09:46 by hqannouc          #+#    #+#             */
/*   Updated: 2025/10/24 22:10:12 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

double	count_distance(t_game game, double r_angle)
{
	double	map_x;
	double	map_y;
	double	distance;

	double	(step) = 0.01;
	distance = 0;
	map_x = game.player.x;
	map_y = game.player.y;
	while (1)
	{
		map_x += step * cos(r_angle);
		map_y += step * sin(r_angle);
		distance += step;
		if (game.scene.map[(int)map_y][(int)map_x] == '1')
		{
			break;
		}
	}
	return (distance);
}

void	draw_ray(t_game *game, double r_angle, int x)
{
	double	distance;
	double	wall_height;
	int		y;

	y = 0;
	distance = count_distance(*game, r_angle);
	wall_height = game->win_height / distance;
	//DRAWING the ceiling
	while (y < ((game->win_height) - wall_height) / 2)
	{
		if (game->img_data && game->img_data->addr)
			my_mlx_pixel_put(game->img_data, x, y, 0x005599FF);
			// mlx_pixel_put(game->mlx, game->win, x, y, 0x005599FF);
		y++;
	}
	//DRAWING the wall
	int	wall_end;
	wall_end = y + (int)wall_height;
	if (wall_end > game->win_height)
		wall_end = game->win_height;
	while (y < wall_end)
	{
		if (game->img_data && game->img_data->addr)
			my_mlx_pixel_put(game->img_data, x, y, 0x00AA00AA);
			// mlx_pixel_put(game->mlx, game->win, x, y, 0x00AA00AA);
		y++;
	}
	//DRAWING the floor
	while (y < (game->win_height))
	{
		if (game->img_data && game->img_data->addr)
			my_mlx_pixel_put(game->img_data, x, y, 0x00777733);
			// mlx_pixel_put(game->mlx, game->win, x, y, 0x00777733);
		y++;
	}
}

void draw_fov(t_game *game)
{
	double	r_angle;
	int		x;

	x = 0;
	r_angle = game->player.angle - (deg_to_rad(FOV) / 2);
	while (x < game->win_width)
	{
		draw_ray(game, r_angle, x);
		r_angle += deg_to_rad(FOV) / game->win_width;
		x += 1;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img_data->img, 0, 0);
}
