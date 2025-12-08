/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:23:05 by hqannouc          #+#    #+#             */
/*   Updated: 2025/12/08 21:17:48 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube_bonus.h"

double	deg_to_rad(double angle)
{
	return (angle * (PI / 180));
}

void	get_player_dir(char dir, t_player *player)
{
	if (dir == 'N')
		player->angle = deg_to_rad(-90);
	else if (dir == 'S')
		player->angle = deg_to_rad(90);
	else if (dir == 'E')
		player->angle = deg_to_rad(0);
	else if (dir == 'W')
		player->angle = deg_to_rad(180);
}

void	init_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->scene.map[i])
	{
		j = 0;
		while (game->scene.map[i][j])
		{
			if (is_player(game->scene.map[i][j]))
			{
				game->player.x = (double)j + 0.5;
				game->player.y = (double)i + 0.5;
				get_player_dir(game->scene.map[i][j], &(game->player));
			}
			j++;
		}
		i++;
	}
}

void	init_game(t_game *game, t_scene *scene)
{
	game->win_width = WINDOW_WIDTH;
	game->win_height = WINDOW_HEIGHT;
	game->scene = *scene;
	game->keys = ft_calloc(1, sizeof(t_keys));
	game->keys->a = 0;
	game->keys->w = 0;
	game->keys->s = 0;
	game->keys->d = 0;
	game->keys->left = 0;
	game->keys->right = 0;
	init_player(game);
}

void	parse_scene(t_scene *scene, char *file_path)
{
	if (!get_scene_info(scene, file_path))
		exit(0);
	if (!validate_map(scene, scene->map))
		error_exit(NULL, MAP_ERR);
}
