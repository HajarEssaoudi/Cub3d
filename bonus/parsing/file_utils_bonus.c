/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 22:09:48 by hqannouc          #+#    #+#             */
/*   Updated: 2025/12/09 00:25:44 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

void	cub_check(t_scene *scene, char *filename)
{
	char	*ext;
	char	*name;

	ext = ft_strrchr(filename, '.');
	if (!ext)
		error_exit(scene, CUB_ERR);
	name = ft_strrchr(filename, '/');
	if (!name)
	{
		if (ft_strlen(filename) > 4 && ft_strncmp(ext, ".cub", 4) == 0
			&& ft_strlen(ext) == 4)
			return ;
	}
	else if (ext && ft_strlen(ext) == 4)
	{
		if (ft_strlen(name) > 5 && ft_strncmp(ext, ".cub", 4) == 0)
			return ;
	}
	error_exit(scene, CUB_ERR);
}

int	check_path(t_scene *scene, char *info)
{
	char	*ext;
	char	*name;

	ext = ft_strrchr(info, '.');
	if (!ext)
		return (error_exit(scene, XPM_ERR), 0);
	name = ft_strrchr(info, '/');
	if (!name)
	{
		if (ft_strlen(info) > 4 && ft_strncmp(ext, ".xpm", 4) == 0
			&& ft_strlen(ext) == 4)
			return (1);
	}
	else if (ext && ft_strlen(ext) == 4)
	{
		if (ft_strlen(name) > 5 && ft_strncmp(ext, ".xpm", 4) == 0)
			return (1);
	}
	return (error_exit(scene, XPM_ERR), 0);
}

int	number_of_elements(t_scene *scene, char **map)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!check_id_info(scene, map[i]))
		{
			free(scene->pars->unsplit);
			error_exit(scene, CONFIG_ERR);
		}
		i++;
	}
	if (!check_id_info(scene, map[i]))
		return (6);
	else
		return (7);
}

char	*read_file_to_string(int fd)
{
	char	*line;
	char	*temp;
	char	*to_split;

	to_split = ft_strdup_gnl("");
	if (!to_split)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		temp = to_split;
		to_split = ft_strjoin_gnl(temp, line);
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	return (to_split);
}
