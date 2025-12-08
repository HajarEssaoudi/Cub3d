/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:33:58 by hqannouc          #+#    #+#             */
/*   Updated: 2025/12/08 19:03:30 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

void	print_error(char *err)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(err, 2);
}

void	error_exit(t_scene *scene, char *err)
{
	if (scene)
	{
		if (scene->pars && scene->pars->unsplit)
			scene->pars->unsplit = NULL;
	}
	get_next_line(-1);
	gc_free_all();
	print_error(err);
	exit(1);
}
