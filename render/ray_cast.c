/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:09:46 by hqannouc          #+#    #+#             */
/*   Updated: 2025/11/19 16:53:53 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	dda_loop(t_game *game, t_ray *ray, double *side_dx, double *side_dy)
{
	while (1)
	{
		if (*side_dx <= *side_dy)
		{
			ray->side = 0;
			ray->map_x += ray->step_x;
			if (game->scene.map[ray->map_y][ray->map_x] != '0'
				&& !is_player(game->scene.map[ray->map_y][ray->map_x]))
				break ;
			else
				*side_dx += ray->delta_x;
		}
		else
		{
			ray->side = 1;
			ray->map_y += ray->step_y;
			if (game->scene.map[ray->map_y][ray->map_x] != '0'
				&& !is_player(game->scene.map[ray->map_y][ray->map_x]))
				break ;
			else
				*side_dy += ray->delta_y;
		}
	}
}

double	count_dist(t_game *game, t_ray *ray)
{
	double	dist_to_x;
	double	dist_to_y;
	double	side_dx;
	double	side_dy;

	if (ray->step_x > 0)
		dist_to_x = ceil(game->player.x) - game->player.x;
	else
		dist_to_x = game->player.x - floor(game->player.x);
	if (ray->step_y > 0)
		dist_to_y = ceil(game->player.y) - game->player.y;
	else
		dist_to_y = game->player.y - floor(game->player.y);
	side_dx = dist_to_x / fabs(cos(ray->angle));
	side_dy = dist_to_y / fabs(sin(ray->angle));
	dda_loop(game, ray, &side_dx, &side_dy);
	get_wall_dir(ray);
	if (ray->side == 0)
		return (side_dx);
	else
		return (side_dy);
}

void	draw_floor_ceiling(t_game *game, int x)
{
	int	y;

	y = 0;
	while (y < (game->win_height / 2))
	{
		if (game->img_data && game->img_data->addr)
			my_mlx_pixel_put(game->img_data, x, y, game->scene.c_color);
		y++;
	}
	while (y < game->win_height)
	{
		if (game->img_data && game->img_data->addr)
			my_mlx_pixel_put(game->img_data, x, y, game->scene.f_color);
		y++;
	}
}

void	draw_ray(t_game *game, double r_angle, int x)
{
	double	r_distance;
	double	perp_distance;
	t_ray	*ray;

	ray = ft_calloc(1, sizeof(t_ray));
	init_ray(game, r_angle, ray, x);
	r_distance = count_dist(game, ray);
	perp_distance = r_distance * cos(r_angle - game->player.angle);
	if (perp_distance < 0.01)
		perp_distance = 0.01;
	ray->wall_height = game->win_height / perp_distance;
	draw_floor_ceiling(game, x);
	if (ray->side == 0)
		ray->wall_x = game->player.y + r_distance * sin(ray->angle);
	else
		ray->wall_x = game->player.x + r_distance * cos(ray->angle);
	ray->wall_x = ray->wall_x - floor(ray->wall_x);
	sample_texture(game, ray, game->textures[ray->wall_dir]);
}

void	draw_3d_fov(t_game *game)
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
