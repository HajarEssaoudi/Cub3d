/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:36:07 by hes-saou          #+#    #+#             */
/*   Updated: 2025/10/25 11:38:37 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	handle_close_button(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	gc_free_all();
	exit(0);
	return (0);
}
