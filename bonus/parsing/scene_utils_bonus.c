/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:36:25 by hqannouc          #+#    #+#             */
/*   Updated: 2025/12/08 22:48:29 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

char	**return_scene(t_scene *scene, char *filename)
{
	int		fd;
	char	**info;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(scene, FILE_ERR);
	cub_check(scene, filename);
	scene->pars->unsplit = read_file_to_string(fd);
	close(fd);
	if (!scene->pars->unsplit)
		error_exit(scene, EMPTY_ERR);
	info = ft_split(scene->pars->unsplit, '\n');
	if (!info)
		return (NULL);
	return (info);
}

void	get_map_layout(t_scene *scene, char **conf_map, int j)
{
	int		height;
	int		i;

	if (!scene)
		return ;
	height = 0;
	i = 0;
	while (conf_map[height] && *conf_map[height] != '\n')
		height++;
	scene->map = gc_malloc(sizeof(char *) * ((height - j) + 1));
	if (!scene->map)
		return ;
	height = 0;
	i = j;
	while (conf_map[i])
		scene->map[height++] = ft_strdup(conf_map[i++]);
	scene->map[height] = NULL;
}

int	check_null_config(t_scene *cfg, int n)
{
	if (!cfg->n_path || !cfg->s_path || !cfg->e_path || !cfg->w_path)
		return (0);
	if (n == 7 && !cfg->d_path)
		return (0);
	if (!cfg->pars->f_is_set || !cfg->pars->c_is_set)
		return (0);
	return (1);
}

int	no_empty_lines(t_scene *scene, char **conf_map)
{
	int	i;
	int	j;

	i = ft_strstr_index(scene->pars->unsplit, conf_map[7]);
	if (i < 0)
		return (0);
	while (scene->pars->unsplit[i])
	{
		if (scene->pars->unsplit[i] == '\n'
			&& scene->pars->unsplit[i + 1] == '\n')
		{
			j = i + 2;
			while (scene->pars->unsplit[j] && (scene->pars->unsplit[j] == '\n'
					|| scene->pars->unsplit[j] == ' '))
				j++;
			if (scene->pars->unsplit[j] == '\0')
				return (1);
			free(scene->pars->unsplit);
			return (0);
		}
		i++;
	}
	return (1);
}

int	get_scene_info(t_scene *scene, char *filename)
{
	int		n;
	char	**conf_map;

	n = 0;
	conf_map = return_scene(scene, filename);
	if (!conf_map)
		error_exit(scene, EMPTY_ERR);
	n = number_of_elements(scene, conf_map);
	if (!check_null_config(scene, n))
		error_exit(scene, CONFIG_ERR);
	if (!no_empty_lines(scene, conf_map))
		error_exit(scene, EMPTY_ERR);
	free(scene->pars->unsplit);
	get_map_layout(scene, conf_map, n);
	if (n == 7)
		scene->has_door = 1;
	return (n);
}
