/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:59:33 by hqannouc          #+#    #+#             */
/*   Updated: 2025/12/09 00:32:58 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube_bonus.h"

void	draw_square(t_img_data *img, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			my_mlx_pixel_put(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_mini_fov(t_game *game)
{
	double	r_angle;
	double	x;
	double	y;
	t_ray	ray;
	int		r;

	r = 0;
	r_angle = game->player.angle - (deg_to_rad(FOV) / 2);
	while (r < game->win_width)
	{
		init_ray(game, r_angle, &ray, r);
		ray.distance = count_dist(game, &ray) * 15;
		x = (game->player.x * 15);
		y = (game->player.y * 15);
		while (ray.distance > 1)
		{
			x += cos(ray.angle);
			y += sin(ray.angle);
			my_mlx_pixel_put(game->img_data, (int)x, (int)y, 0xFFFF00);
			ray.distance--;
		}
		r_angle += deg_to_rad(FOV) / game->win_width;
		r++;
	}
}

void	draw_player(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = (game->player.x) * TILE_SIZE;
	y = (game->player.y) * TILE_SIZE;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			my_mlx_pixel_put(game->img_data, x + i, y + j, 0xFF0000);
			j++;
		}
		i++;
	}
}

void	set_cell_color(char cell, int *color)
{
	if (cell == '1')
		*color = 0x00888888;
	else if (cell == '_')
		*color = 0x00505050;
	else if (cell == '0' || is_player(cell))
		*color = 0x00006611;
	else if (cell == 'd')
		*color = 0x00005411;
	else
		*color = 0x00AA0000;
}

void	draw_mini_map(t_game *game)
{
	int	j;
	int	color;

	int (i) = 0;
	while (game->scene.map_pad[i])
	{
		j = 0;
		while (game->scene.map_pad[i][j])
		{
			set_cell_color(game->scene.map_pad[i][j], &color);
			draw_square(game->img_data, j * 15, i * 15, color);
			j++;
		}
		i++;
	}
	draw_player(game);
	draw_mini_fov(game);
	draw_frame(j, i, game);
	mlx_put_image_to_window(game->mlx, game->win, game->img_data->img, 0, 0);
}
