/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:28:56 by hqannouc          #+#    #+#             */
/*   Updated: 2025/12/03 22:37:30 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_bonus.h"

double	angle_range_2pi(double angle)
{
	while (angle < 0)
		angle += 2 * PI;
	while (angle >= 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

void	init_ray(t_game *game, double r_angle, t_ray *ray, int x)
{
	ray->angle = angle_range_2pi(r_angle);
	ray->window_x = x;
	ray->map_x = floor(game->player.x);
	ray->map_y = floor(game->player.y);
	ray->delta_x = fabs(1 / cos(ray->angle));
	ray->delta_y = fabs(1 / sin(ray->angle));
	ray->side = 0;
	if (cos(ray->angle) < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (sin(ray->angle) < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
	ray->wall_height = 0;
}

void	get_wall_dir(t_ray *ray, int is_door)
{
	if (is_door)
		ray->wall_dir = DO;
	else if (ray->side == 0)
	{
		if (ray->step_x > 0)
			ray->wall_dir = WE;
		else
			ray->wall_dir = EA;
	}
	else
	{
		if (ray->step_y > 0)
			ray->wall_dir = NO;
		else
			ray->wall_dir = SO;
	}
}
