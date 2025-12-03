/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatim <hqannouc@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 22:12:28 by hqannouc          #+#    #+#             */
/*   Updated: 2025/11/23 15:58:09 by hatim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

void	height_width(t_scene *scene)
{
	size_t	max_width;
	int		i;

	i = 0;
	max_width = 0;
	while (scene->map[i])
	{
		if (ft_strlen(scene->map[i]) > max_width)
			max_width = ft_strlen(scene->map[i]);
		i++;
	}
	scene->map_height = i;
	scene->map_width = max_width;
}

char	**duplicate_map(char **map, int height)
{
	int		i;
	char	**dup;

	dup = gc_malloc(sizeof(char *) * (height + 1));
	i = -1;
	while (++i < height)
	{
		dup[i] = ft_strdup(map[i]);
	}
	dup[i] = NULL;
	return (dup);
}

char	**add_padding(t_scene scene)
{
	char	**dup;
	char	*new_line;
	int		j;

	int (i) = 0;
	dup = duplicate_map(scene.map, scene.map_height);
	while (i < scene.map_height)
	{
		new_line = gc_malloc(sizeof(char) * (scene.map_width + 1));
		j = 0;
		while (dup[i][j] && j < scene.map_width)
		{
			if (dup[i][j] == ' ')
				new_line[j] = '_';
			else
				new_line[j] = dup[i][j];
			j++;
		}
		while (j < scene.map_width)
			new_line[j++] = '_';
		new_line[j] = '\0';
		dup[i] = new_line;
		i++;
	}
	return (dup);
}
