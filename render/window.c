/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:16:43 by hes-saou          #+#    #+#             */
/*   Updated: 2025/10/24 22:28:10 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"
#include <stdlib.h>

int	handle_close_button(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	gc_free_all();
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	mlx_draw_mini_map(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	tile;

	tile = 16;
	i = 0;
	while (game->scene.map[i])
	{
		j = 0;
		while (game->scene.map[i][j])
		{
			int color = 0x000000;
			if (game->scene.map[i][j] == '1')
				color = 0xFFFF00;
			else if (game->scene.map[i][j] == '0')
				color = 0xAAAAAA;
			else if (is_player(game->scene.map[i][j]))
				color = 0xFF0000;
			y = 0;
			while (y < tile)
			{
				x = 0;
				while (x < tile)
				{
					my_mlx_pixel_put(game->img_data, j * tile + x, i * tile + y, color);
					x++;
				}
				y++;
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img_data->img, 0, 0);
}

// void	draw_square(t_img_data *img, int x, int y, int size, int color)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			my_mlx_pixel_put(img, x + j, y + i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	draw_player(t_game *game, int tile)
// {
// 	int	player_size;
// 	int	x;
// 	int	y;

// 	player_size = tile / 3;
// 	x = (int)(game->player.x * tile - player_size / 3);
// 	y = (int)(game->player.y * tile - player_size / 3);
// 	draw_square(game->img_data, x, y, player_size, 0xFF0000);
// }

// void	mlx_draw_mini_map(t_game *game)
// {
// 	int	i;
// 	int	j;
// 	int	tile;
// 	int	color;

// 	tile = 26;
// 	i = 0;
// 	while (game->map->layout[i])
// 	{
// 		j = 0;
// 		while (game->map->layout[i][j])
// 		{
// 			color = 0x000000;
// 			if (game->map->layout[i][j] == '1')
// 				color = 0xFFFFFF;
// 			draw_square(game->img_data, j * tile, i * tile, tile, color);
// 			j++;
// 		}
// 		i++;
// 	}
// 	draw_player(game, tile);
// 	mlx_put_image_to_window(game->mlx, game->win,
// 		game->img_data->img, 0, 0);
// }

// void	mlx_draw_mini_map(t_game *game)
// {
// 	int	i;
// 	int	j;
// 	int	tile;
// 	int	gap;
// 	int	color;

// 	tile = 14;
// 	gap = 2;
// 	i = 0;
// 	while (game->scene.map[i])
// 	{
// 		j = 0;
// 		while (game->scene.map[i][j])
// 		{
// 			color = 0x000000;
// 			if (game->scene.map[i][j] == '1')
// 				color = 0xFFFFFF;
// 			draw_square(game->img_data, j * (tile + gap), i * (tile + gap), tile, color);
// 			j++;
// 		}
// 		i++;
// 	}
// 	draw_player(game, tile);
// 	mlx_put_image_to_window(game->mlx, game->win, game->img_data->img, 0, 0);
// }


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
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		gc_free_all();
		exit(0);
	}
	if (keycode == W)
	{
		game->player.x += cos(game->player.angle) * 0.1;
		game->player.y += sin(game->player.angle) * 0.1;
	}	
	else if (keycode == S)
	{
		game->player.x -= cos(game->player.angle) * 0.1;
		game->player.y -= sin(game->player.angle) * 0.1;
	}
	else if (keycode == D)
	{
		game->player.x -= sin(game->player.angle) * 0.1;
		game->player.y += cos(game->player.angle) * 0.1;
	}
	else if (keycode == A)
	{
		game->player.x += sin(game->player.angle) * 0.1;
		game->player.y -= cos(game->player.angle) * 0.1;
	}
	else if (keycode == LEFT_ARROW)
		game->player.angle -= deg_to_rad(5);
	else if (keycode == RIGHT_ARROW)
		game->player.angle += deg_to_rad(5);
	mlx_clear_window(game->mlx, game->win);
	draw_fov(game);
	return (0);
}

void	render_window(t_scene *scene, t_game *game)
{
	(void)scene;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, "Cub3D");
	init_img(game);
	draw_fov(game);
	mlx_hook(game->win, 2, 1 << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, handle_close_button, game);
	mlx_loop(game->mlx);
}
