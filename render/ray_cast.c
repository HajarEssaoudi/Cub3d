/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:09:46 by hqannouc          #+#    #+#             */
/*   Updated: 2025/10/31 01:38:01 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

double angle_range_2pi(double angle)
{
	while (angle < 0)
		angle += TWO_PI;
	while (angle >= TWO_PI)
		angle -= TWO_PI;
	return (angle);
}

void init_ray(t_game *game, double r_angle, t_ray *ray)
{
	r_angle = angle_range_2pi(r_angle);
	ray->map_x = floor(game->player.x);
	ray->map_y = floor(game->player.y);
	ray->delta_x = fabs(1 / cos(r_angle));
	ray->delta_y = fabs(1 / sin(r_angle));
	if (cos(r_angle) < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (sin(r_angle) < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
	ray->is_hit = 0;
}

double	count_dist(t_game *game, double r_angle, t_ray *ray)
{
	double	dist_to_x;
	double	dist_to_y;

	if (ray->step_x > 0)
		dist_to_x = ceil(game->player.x) - game->player.x;
	else
		dist_to_x = game->player.x - floor(game->player.x);
	if (ray->step_y > 0)
		dist_to_y = ceil(game->player.y) - game->player.y;
	else
		dist_to_y = game->player.y - floor(game->player.y);
	ray->side_dx = dist_to_x / fabs(cos(r_angle));
	ray->side_dy = dist_to_y / fabs(sin(r_angle));
	while (1)
	{
		if (ray->is_hit)
			break ;
		if (ray->side_dx <= ray->side_dy)
		{
			ray->map_x += ray->step_x;
			if (game->scene.map[ray->map_y][ray->map_x] == '1')
				break ;
			else
				ray->side_dx += ray->delta_x;
		}
		else
		{
			ray->map_y += ray->step_y;
			if (game->scene.map[ray->map_y][ray->map_x] == '1')
				break ;
			else
				ray->side_dy += ray->delta_y;
		}
	}
	if (ray->side_dx < ray->side_dy)
		return (ray->side_dx);
	else
		return (ray->side_dy);
}

void	draw_ray(t_game *game, double r_angle, int x)
{
	double	r_distance;
	double	perp_distance;
	double	wall_height;
	int		wall_end;
	t_ray	*ray;
	int		y;

	y = 0;
	ray = ft_calloc(1, sizeof(t_ray));
	init_ray(game, r_angle, ray);
	r_distance = count_dist(game, r_angle, ray);
	perp_distance = r_distance * cos(r_angle - game->player.angle);
	wall_height = game->win_height / perp_distance;
	// wall_height = game->win_height / r_distance;
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
			my_mlx_pixel_put(game->img_data, x, y, 0x00662255);
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
