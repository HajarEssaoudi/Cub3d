/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_by_steps_algo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:41:58 by hes-saou          #+#    #+#             */
/*   Updated: 2025/10/31 17:24:21 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

// char	get_wall_direction(double r_angle)
// {
	
// }

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
			// ray.wall_dir = get_wall_direction(r_angle);
			break;
		}
	}
	return (distance);
}

void	draw_ray(t_game *game, double r_angle, int x)
{
	double	r_distance;
	double	perp_distance;
	double	wall_height;
	int		wall_end;
	int		y;

	y = 0;
	r_distance = count_distance(*game, r_angle);
	// perp_distance = r_distance * cos(r_angle - game->player.angle);
	// wall_height = game->win_height / perp_distance;
	wall_height = game->win_height / r_distance;
	//DRAWING the ceiling
	while (y < ((game->win_height) - wall_height) / 2)
	{
		if (game->img_data && game->img_data->addr)
			my_mlx_pixel_put(game->img_data, x, y, game->scene.c_colors);
		y++;
	}
	//DRAWING the wall
	wall_end = y + (int)wall_height;
	if (wall_end > game->win_height)
		wall_end = game->win_height;
	while (y < wall_end) 
	{
		if (game->img_data && game->img_data->addr)
			my_mlx_pixel_put(game->img_data, x, y, 0x00006600);
		y++;
	}
	//DRAWING the floor
	while (y < (game->win_height))
	{
		if (game->img_data && game->img_data->addr)
			my_mlx_pixel_put(game->img_data, x, y, game->scene.f_colors);
		y++;
	}
}

void draw_3d_fov(t_game *game)
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