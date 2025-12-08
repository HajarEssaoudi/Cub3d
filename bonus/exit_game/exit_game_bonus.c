/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:36:07 by hes-saou          #+#    #+#             */
/*   Updated: 2025/12/09 00:30:21 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_bonus.h"

void	free_game(t_game *game)
{
	int	i;
	int	n;

	i = 0;
	if (game->scene.has_door == 1)
		n = 5;
	else
		n = 4;
	while (i < n)
	{
		if (game && game->textures[i].img)
			mlx_destroy_image(game->mlx, game->textures[i].img);
		i++;
	}
	if (game && game->img_data && game->img_data->img)
		mlx_destroy_image(game->mlx, game->img_data->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int	handle_close_button(t_game *game)
{
	get_next_line(-1);
	free_game(game);
	gc_free_all();
	exit(0);
	return (0);
}
