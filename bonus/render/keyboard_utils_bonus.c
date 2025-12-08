/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:57:45 by hqannouc          #+#    #+#             */
/*   Updated: 2025/12/08 21:55:02 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_bonus.h"

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
	else if (keycode == M && game->keys->m == 0)
		game->keys->m = 1;
	else if (keycode == M && game->keys->m == 1)
		game->keys->m = 0;
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

char	**change_door_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'D')
				map[i][j] = 'd';
			else if (map[i][j] == 'd')
				map[i][j] = 'D';
			j++;
		}
		i++;
	}
	return (map);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		free_game(game);
		gc_free_all();
		exit(0);
	}
	if (keycode == ENTER)
	{
		game->scene.map_pad = change_door_map(game->scene.map_pad);
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
