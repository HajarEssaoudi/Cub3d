/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:48:37 by hqannouc          #+#    #+#             */
/*   Updated: 2025/11/19 16:40:52 by hqannouc         ###   ########.fr       */
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
			if (map[i][j] != '1' && map[i][j] != '_')
				return (0);
			while (map[i][j] && !is_space(map[i][j]))
				j++;
			if (map[i][j - 2] != '1' && map[i][j - 1] == '_')
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_horizontal_walls(char **map, int height, int width)
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
				if (i - 1 < 0 || map[i - 1][j] == '_')
					return (0);
				if (i + 1 >= height || map[i + 1][j] == '_')
					return (0);
				if (j - 1 < 0 || map[i][j - 1] == '_')
					return (0);
				if (j + 1 >= width || map[i][j + 1] == '_')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_map(t_scene *sc, char **map)
{
	if (!map || !map[0])
		error_exit(NULL, EMPTY_ERR);
	height_width(sc);
	sc->map_pad = add_padding(*sc);
	if (!check_walls(sc->map_pad))
		error_exit(NULL, WALL_ERR);
	if (!no_foreign_elements(map))
		error_exit(NULL, MAP_ERR);
	if (!has_unique_elements(map))
		error_exit(NULL, MAP_ERR);
	if (!check_horizontal_walls(sc->map_pad, sc->map_height, sc->map_width))
		error_exit(NULL, WALL_ERR);
	return (1);
}
