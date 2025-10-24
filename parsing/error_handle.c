/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:33:58 by hqannouc          #+#    #+#             */
/*   Updated: 2025/10/24 17:54:06 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_error(char *err)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(err, 2);
}

void	error_exit(t_scene *scene, char *err)
{
	(void) scene;
	print_error(err);
	exit(0);
}
