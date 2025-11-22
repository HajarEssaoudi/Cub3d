/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:57:45 by hqannouc          #+#    #+#             */
/*   Updated: 2025/11/18 18:27:40 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_key(int keycode, t_game *game)
{
	if (keycode == W)
		game->keys->w = 1;
	else if (keycode == S)
		game->keys->s = 1;
	else if (keycode == D)
		game->keys->d = 1;
	else if (keycode == A)
		game->keys->a = 1;
	else if (keycode == LEFT_ARROW)
		game->keys->left = 1;
	else if (keycode == RIGHT_ARROW)
		game->keys->right = 1;
}

void	move_player(t_game *game, double *x, double *y)
{
	if (game->keys->w == 1)
	{
		*x += cos(game->player.angle) * MOVE_SPEED;
		*y += sin(game->player.angle) * MOVE_SPEED;
	}	
	if (game->keys->s == 1)
	{
		*x -= cos(game->player.angle) * MOVE_SPEED;
		*y -= sin(game->player.angle) * MOVE_SPEED;
	}
	if (game->keys->d == 1)
	{
		*x -= sin(game->player.angle) * MOVE_SPEED;
		*y += cos(game->player.angle) * MOVE_SPEED;
	}
	if (game->keys->a == 1)
	{
		*x += sin(game->player.angle) * MOVE_SPEED;
		*y -= cos(game->player.angle) * MOVE_SPEED;
	}
	if (game->keys->left == 1)
		game->player.angle -= deg_to_rad(ROT_SPEED);
	if (game->keys->right == 1)
		game->player.angle += deg_to_rad(ROT_SPEED);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		gc_free_all();
		exit(0);
	}
	if (!game->keys)
		return (0);
	check_key(keycode, game);
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	if (!game->keys)
		return (0);
	if (keycode == W)
		game->keys->w = 0;
	else if (keycode == S)
		game->keys->s = 0;
	else if (keycode == D)
		game->keys->d = 0;
	else if (keycode == A)
		game->keys->a = 0;
	else if (keycode == RIGHT_ARROW)
		game->keys->right = 0;
	else if (keycode == LEFT_ARROW)
		game->keys->left = 0;
	return (0);
}
