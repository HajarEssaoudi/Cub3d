/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:16:43 by hes-saou          #+#    #+#             */
/*   Updated: 2025/10/30 23:49:23 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"
#include "cube.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	init_img(t_game *game)
{
	game->img_data = gc_malloc(sizeof(t_img_data));
	if (!game->img_data)
		return ;
	game->img_data->img = mlx_new_image(game->mlx, (game->win_width), (game->win_height));
	game->img_data->addr = mlx_get_data_addr(
			game->img_data->img,
			&game->img_data->bpp,
			&game->img_data->line_length,
			&game->img_data->endian);
}

int	handle_keypress(int keycode, t_game *game)
{
	double	x;
	double	y;
	
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		gc_free_all();
		exit(0);
	}
	if (keycode == W)
	{
		x = game->player.x + cos(game->player.angle) * 0.1;
		y = game->player.y + sin(game->player.angle) * 0.1;
		if (game->scene.map[(int)y][(int)x] != '1')
		{
			game->player.x = x;
			game->player.y = y;
		}
	}	
	else if (keycode == S)
	{
		x = game->player.x - cos(game->player.angle) * 0.1;
		y = game->player.y - sin(game->player.angle) * 0.1;
		if (game->scene.map[(int)y][(int)x] != '1')
		{
			game->player.x = x;
			game->player.y = y;
		}
	}
	else if (keycode == D)
	{
		x = game->player.x - sin(game->player.angle) * 0.1;
		y = game->player.y + cos(game->player.angle) * 0.1;
		if (game->scene.map[(int)y][(int)x] != '1')
		{
			game->player.x = x;
			game->player.y = y;
		}
	}
	else if (keycode == A)
	{
		x = game->player.x + sin(game->player.angle) * 0.1;
		y = game->player.y - cos(game->player.angle) * 0.1;
		if (game->scene.map[(int)y][(int)x] != '1')
		{
			game->player.x = x;
			game->player.y = y;
		}
	}
	else if (keycode == LEFT_ARROW)
		game->player.angle -= deg_to_rad(5);
	else if (keycode == RIGHT_ARROW)
		game->player.angle += deg_to_rad(5);
	mlx_clear_window(game->mlx, game->win);
	draw_3d_fov(game);
	draw_mini_map(game); //boinus
	return (0);
}

void render_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, "Cub3D");
	init_img(game);
	draw_3d_fov(game);
	draw_mini_map(game); //bonus
	mlx_hook(game->win, 2, 1 << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, handle_close_button, game);
	mlx_loop(game->mlx);
}
