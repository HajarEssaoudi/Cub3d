/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:14:29 by hqannouc          #+#    #+#             */
/*   Updated: 2025/12/03 00:37:09 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	get_color(t_texture tex, int tex_x, int tex_y)
{
	char	*pixel;

	pixel = tex.addr + (tex_y * tex.line_length) + (tex_x * (tex.bpp / 8));
	return (*(int *)pixel);
}

void	draw_ray_tex(t_game *game, t_ray *ray, int draw_start, t_texture tex)
{
	int	y;
	int	draw_end;
	int	color;

	y = draw_start;
	draw_end = draw_start + ray->wall_height;
	if (draw_end >= game->win_height)
		draw_end = game->win_height - 1;
	while (y <= draw_end)
	{
		ray->tex->y = (int)ray->tex->pos;
		if (ray->tex->y >= 0 && ray->tex->y < tex.height)
		{
			color = get_color(tex, ray->tex->x, ray->tex->y);
			my_mlx_pixel_put(game->img_data, ray->window_x, y, color);
		}
		ray->tex->pos += ray->tex->step;
		y++;
	}
}

void	sample_texture(t_game *game, t_ray *ray, t_texture texture)
{
	int		start;

	ray->tex = gc_malloc(sizeof(t_ray_tex));
	ray->tex->step = (double)texture.height / ray->wall_height;
	ray->tex->x = (int)(ray->wall_x * texture.width);
	start = (game->win_height / 2) - (ray->wall_height / 2);
	if (start < 0)
		start = 0;
	ray->tex->pos = (start - (game->win_height / 2 - ray->wall_height / 2))
		* ray->tex->step;
	draw_ray_tex(game, ray, start, texture);
}
