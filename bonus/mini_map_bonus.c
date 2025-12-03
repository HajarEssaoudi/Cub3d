/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatim <hqannouc@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:59:33 by hqannouc          #+#    #+#             */
/*   Updated: 2025/11/29 15:32:01 by hatim            ###   ########.fr       */
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

void	draw_mi3i_fov(t_game *game)
{
	double	r_angle;
	double	x;
	double	y;
	int		ray;

	ray = 0;
	r_angle = game->player.angle - (deg_to_rad(FOV) / 2);
	
	while (ray < game->win_width)
	{
		x = (game->player.x * 15);
		y = (game->player.y * 15);
		
		while (game->scene.map[((int)(y / 15))][(int)(x / 15)] != '1'
			&& game->scene.map_pad[((int)(y / 15))][(int)(x / 15)] != '_'
			&& game->scene.map[((int)(y / 15))][(int)(x / 15)] != '\0')
		{
			x += cos(r_angle);
			y += sin(r_angle);
			my_mlx_pixel_put(game->img_data, (int)x, (int)y, 0xFFFF00);
		}
		r_angle += deg_to_rad(FOV) / game->win_width;
		ray++;
	}
}

void	draw_mini_fov(t_game *game)
{
	double	r_angle;
	double	r_distance;
	double	x;
	double	y;
	t_ray	ray;
	int		r;

	r = 0;
	r_angle = game->player.angle - (deg_to_rad(FOV) / 2);
	while (r < game->win_width)
	{
		init_ray(game, r_angle, &ray, r);
		r_distance = count_dist(game, &ray) * 15;
		x = (game->player.x * 15);
		y = (game->player.y * 15);
		while (r_distance-- > 0)
		{
			x += cos(ray.angle);
			y += sin(ray.angle);
			if (ray.wall_dir == NO)
				my_mlx_pixel_put(game->img_data, (int)x, (int)y, 0xFFFF00);
			else if (ray.wall_dir == SO)
				my_mlx_pixel_put(game->img_data, (int)x, (int)y, 0xFF0000);
			else if (ray.wall_dir == EA)
				my_mlx_pixel_put(game->img_data, (int)x, (int)y, 0x00FF00);
			else if (ray.wall_dir == WE)
				my_mlx_pixel_put(game->img_data, (int)x, (int)y, 0x00FFFF);
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
	else
		*color = 0x00006688;
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
