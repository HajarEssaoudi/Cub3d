/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:00:08 by hqannouc          #+#    #+#             */
/*   Updated: 2025/10/29 10:43:25 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parsing.h"
#include "./includes/cube.h"

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

void init_game(t_game *game, t_scene *scene)
{
	game->win_width = 1500;
	game->win_height = 900;
	game->scene = *scene;
	init_player(game);
}

void parse_scene(t_scene *scene, char *file_path)
{
	if (!get_scene_info(scene, file_path))
		exit(0);
	if (!validate_map(scene, scene->map))
		error_exit(NULL, MAP_ERR);
}

int	main(int argc, char **argv)
{
	t_game *game;
	t_scene	*scene;

	if (argc != 2)
		error_exit(NULL, ARGS_ERR);
	scene = ft_calloc(1, sizeof(t_scene));
	scene->pars = ft_calloc(1, sizeof(t_pars));
	parse_scene(scene, argv[1]);
	if (!get_scene_info(scene, argv[1]))
		return (1);
	if (!validate_map(scene, scene->map))
		return (1);
	game = ft_calloc(1, sizeof(t_game));
	init_game(game, scene);
	render_window(game);
	gc_free_all();
	return (0);
}
