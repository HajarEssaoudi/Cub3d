/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:20:53 by hqannouc          #+#    #+#             */
/*   Updated: 2025/12/09 00:10:53 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	get_color(char *str)
{
	int	result;
	int	i;

	i = 0;
	if (!str)
		return (-1);
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if (result > 255)
			return (-1);
	}
	if (str[i] != '\0')
		return (-1);
	return (result);
}

int	set_color(t_scene *scene, char **colors, char id)
{
	int	red;
	int	green;
	int	blue;

	red = get_color(colors[0]);
	green = get_color(colors[1]);
	blue = get_color(colors[2]);
	if (red < 0 || green < 0 || blue < 0)
		return (0);
	if (id == 'F')
	{
		scene->f_color = (red << 16) | (green << 8) | blue;
		return (scene->pars->f_is_set = 1, 1);
	}
	if (id == 'C')
	{
		scene->c_color = (red << 16) | (green << 8) | blue;
		return (scene->pars->c_is_set = 1, 1);
	}
	return (0);
}

int	floor_ceiling(t_scene *scene, char *info, char id)
{
	char			**colors;

	colors = ft_split(info, ',');
	if (colors[3])
		return (0);
	if (set_color(scene, colors, id))
		return (1);
	return (0);
}

int	id_type(t_scene *scene, char *id, char *info)
{
	if (ft_strlen(id) == 2)
	{
		if (ft_strncmp(id, "NO", 2) == 0 && check_path(scene, info))
			return (scene->n_path = ft_strdup(info), 1);
		if (ft_strncmp(id, "SO", 2) == 0 && check_path(scene, info))
			return (scene->s_path = ft_strdup(info), 1);
		if (ft_strncmp(id, "EA", 2) == 0 && check_path(scene, info))
			return (scene->e_path = ft_strdup(info), 1);
		if (ft_strncmp(id, "WE", 2) == 0 && check_path(scene, info))
			return (scene->w_path = ft_strdup(info), 1);
		return (0);
	}
	return (0);
}

int	check_id_info(t_scene *scene, char *line)
{
	char	**split_line;
	char	*id;
	char	*info;

	split_line = ft_split(line, ' ');
	if (!split_line)
		return (0);
	if (!split_line[0] || !split_line[1] || split_line[2])
		return (0);
	id = ft_strdup(split_line[0]);
	info = ft_strdup(split_line[1]);
	if (ft_strlen(id) == 2)
	{
		if (!id_type(scene, id, info))
			return (0);
	}
	else if (ft_strlen(id) == 1)
	{
		if (!floor_ceiling(scene, info, id[0]))
			return (0);
	}
	else
		return (0);
	return (1);
}
