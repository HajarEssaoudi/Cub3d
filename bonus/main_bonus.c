/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:00:08 by hqannouc          #+#    #+#             */
/*   Updated: 2025/12/08 21:11:13 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube_bonus.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	t_scene	*scene;

	if (argc != 2)
		error_exit(NULL, ARGS_ERR);
	scene = ft_calloc(1, sizeof(t_scene));
	scene->pars = ft_calloc(1, sizeof(t_pars));
	parse_scene(scene, argv[1]);
	game = ft_calloc(1, sizeof(t_game));
	init_game(game, scene);
	render_window(game);
	get_next_line(-1);
	gc_free_all();
	return (0);
}
