/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:59:33 by hqannouc          #+#    #+#             */
/*   Updated: 2025/10/29 14:11:09 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube_bonus.h"


void	draw_square(t_img_data *img, int x, int y, int color, int tile_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < tile_size)
	{
		j = 0;
		while (j < tile_size)
		{
			my_mlx_pixel_put(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_frame(int j, int i, t_game *game)
{
	int	width;
	int	height;
	int	t;
	int	x;
	int	y;

	width = j * 15;
	height = i * 15;
	t = -1;
	while (++t < 7 && (x = -1))
	{
		while (++x < width)
		{
			my_mlx_pixel_put(game->img_data, x, t, 0x808080);
			my_mlx_pixel_put(game->img_data, x, height - 1 - t, 0x808080);
		}
	}
	t = -1;
	while (++t < 7 && (y = -1))
	{
		while (++y < height)
		{
			my_mlx_pixel_put(game->img_data, t, y, 0x808080);
			my_mlx_pixel_put(game->img_data, width - 1 - t, y, 0x808080);
		}
	}
}

void	draw_mini_fov(t_game *game)
{
	double r_angle;
	double		x;
	double		y;
	int		ray;

	ray = 0;
	r_angle = game->player.angle - (deg_to_rad(FOV) / 2);
	while (ray < game->win_width)
	{
		x = (game->player.x * 15);
		y = (game->player.y * 15);
		while (game->scene.map[((int)(y / 15))][(int)(x / 15)] != '1')
		{
			x += cos(r_angle);
			y += sin(r_angle);
			my_mlx_pixel_put(game->img_data, (int)x, (int)y, 0xFFFF00);
		}
		r_angle += deg_to_rad(FOV) / game->win_width;
		ray++;
	}
}

void	draw_player(t_game *game, int tile_size)
{
	int	x;
	int	y;

	x = (game->player.x) * tile_size;
	y = (game->player.y) * tile_size;
	draw_square(game->img_data, x, y, 0xFF0000, 3);
}

void	draw_mini_map(t_game *game)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (game->scene.map_pad[i])
	{
		j = 0;
		while (game->scene.map_pad[i][j])
		{
			if (game->scene.map_pad[i][j] == '1')
				color = 0x00009900;
			else if (game->scene.map_pad[i][j] == '0' || is_player(game->scene.map_pad[i][j]))
				color = 0x005A3A22;
			else
				color = 0x00000030;
			draw_square(game->img_data, j * 15, i * 15, color, 15);
			j++;
		}
		i++;
	}
	draw_player(game, 15);
	draw_mini_fov(game);
	draw_frame(j, i, game);
	mlx_put_image_to_window(game->mlx, game->win, game->img_data->img, 0, 0);
}
