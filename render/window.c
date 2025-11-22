/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:16:43 by hes-saou          #+#    #+#             */
/*   Updated: 2025/11/22 20:30:00 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	init_img(t_game *game)
{
	game->img_data = gc_malloc(sizeof(t_img_data));
	if (!game->img_data)
		return ;
	game->img_data->img = mlx_new_image(game->mlx,
			(game->win_width), (game->win_height));
	game->img_data->addr = mlx_get_data_addr(
			game->img_data->img,
			&game->img_data->bpp,
			&game->img_data->line_length,
			&game->img_data->endian);
}

static int	loop_update(void *param)
{
	t_game	*game;
	double	x;
	double	y;

	game = (t_game *)param;
	if (!game || !game->keys)
		return (0);
	x = game->player.x;
	y = game->player.y;
	move_player(game, &x, &y);
	if (y > 1 && y < (game->scene.map_height - 1)
		&& x > 1 && x < (game->scene.map_width - 1)
		&& game->scene.map[(int)(y)][(int)(x)] != '\0'
		&& game->scene.map[(int)(y)][(int)(x)] != ' ')
	{
		game->player.x = x;
		game->player.y = y;
	}
	mlx_clear_window(game->mlx, game->win);
	draw_3d_fov(game);
	return (0);
}

void	render_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			game->win_width, game->win_height, "Cub3D");
	init_img(game);
	init_textures(game);
	draw_3d_fov(game);
	mlx_hook(game->win, 2, 1 << 0,  handle_keypress, game);
	mlx_hook(game->win, 3, 1 << 1, handle_keyrelease, game);
	mlx_hook(game->win, 17, 0, handle_close_button, game);
	mlx_loop_hook(game->mlx, loop_update, game);
	mlx_loop(game->mlx);
}
