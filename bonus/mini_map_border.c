/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_border.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatim <hqannouc@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:07:03 by hatim             #+#    #+#             */
/*   Updated: 2025/11/29 11:21:44 by hatim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube_bonus.h"

static void	draw_horizontal_border(t_game *game, int width, int height)
{
	int	t;
	int	x;

	t = 0;
	while (t < 7)
	{
		x = 0;
		while (x < width)
		{
			my_mlx_pixel_put(game->img_data, x, t, 0x505050);
			my_mlx_pixel_put(game->img_data, x, height - 1 - t, 0x505050);
			x++;
		}
		t++;
	}
}

static void	draw_vertical_border(t_game *game, int width, int height)
{
	int	t;
	int	y;

	t = 0;
	while (t < 7)
	{
		y = 0;
		while (y < height)
		{
			my_mlx_pixel_put(game->img_data, t, y, 0x505050);
			my_mlx_pixel_put(game->img_data, width - 1 - t, y, 0x505050);
			y++;
		}
		t++;
	}
}

void	draw_frame(int j, int i, t_game *game)
{
	int	width;
	int	height;

	width = j * 15;
	height = i * 15;
	draw_horizontal_border(game, width, height);
	draw_vertical_border(game, width, height);
}
