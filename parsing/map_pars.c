/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:48:37 by hqannouc          #+#    #+#             */
/*   Updated: 2025/09/20 22:22:01 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	no_foreign_elements(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_valid_element(map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	has_unique_elements(char **map)
{
	int	p;
	int	i;
	int	j;

	p = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player(map[i][j]))
				p++;
			j++;
		}
		i++;
	}
	return (p == 1);
}

static int	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			skip_whitespace(map[i], &j);
			if (map[i][j] != '1')
				return (0);
			while (map[i][j] && !is_space(map[i][j]))
				j++;
			if (map[i][j - 1] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_horizontal_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_valid_element(map[i][j]) && map[i][j] != '1')
			{
				if (map[i - 1][j] == '_' || map[i + 1][j] == '_')
					return (0);
				if (map[i][j - 1] == '_' || map[i][j + 1] == '_')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_map(t_scene *scene, char **map)
{
	char	**padded;

	if (!map || !map[0])
		return (print_error(EMPTY_ERR), 0);
	if (!check_walls(map))
		return (print_error(WALL_ERR), 0);
	if (!no_foreign_elements(map))
		return (print_error(MAP_ERR), 0);
	if (!has_unique_elements(map))
		return (print_error(MAP_ERR), 0);
	height_width(scene);
	padded = add_padding(*scene);
	if (!check_horizontal_walls(padded))
		return (print_error(WALL_ERR), 0);
	return (1);
}
