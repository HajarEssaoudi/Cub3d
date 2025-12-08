/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:50:41 by hqannouc          #+#    #+#             */
/*   Updated: 2025/12/08 22:05:15 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_bonus.h"

static void	load_texture_image(t_game *g, int direction, char *path)
{
	g->textures[direction].img = mlx_xpm_file_to_image(g->mlx, path,
			&g->textures[direction].width, &g->textures[direction].height);
	if (!g->textures[direction].img)
		error_exit(&(g->scene), IMG_ERR);
}

static void	get_texture_data(t_game *g, int direction)
{
	g->textures[direction].addr = mlx_get_data_addr(
			g->textures[direction].img,
			&g->textures[direction].bpp,
			&g->textures[direction].line_length,
			&g->textures[direction].endian);
	if (!g->textures[direction].addr)
		error_exit(&(g->scene), IMG_ERR);
}

void	init_textures(t_game *g)
{
	load_texture_image(g, NO, g->scene.n_path);
	load_texture_image(g, SO, g->scene.s_path);
	load_texture_image(g, EA, g->scene.e_path);
	load_texture_image(g, WE, g->scene.w_path);
	get_texture_data(g, NO);
	get_texture_data(g, SO);
	get_texture_data(g, EA);
	get_texture_data(g, WE);
	if (g->scene.has_door)
	{
		load_texture_image(g, DO, g->scene.d_path);
		get_texture_data(g, DO);
	}
}
