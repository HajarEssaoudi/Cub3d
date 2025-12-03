/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:00:08 by hqannouc          #+#    #+#             */
/*   Updated: 2025/12/03 23:11:27 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	t_scene	*scene;

	if (argc != 2)
		error_exit(NULL, ARGS_ERR);
	scene = ft_calloc(1, sizeof(t_scene));
	scene->pars = ft_calloc(1, sizeof(t_pars));
	parse_scene(scene, argv[1]);
	// gc_free_all();
	// exit(0);
	game = ft_calloc(1, sizeof(t_game));
	init_game(game, scene);
	render_window(game);
	return (0);
}
