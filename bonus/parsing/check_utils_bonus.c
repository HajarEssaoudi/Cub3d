/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatim <hqannouc@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:05:27 by hqannouc          #+#    #+#             */
/*   Updated: 2025/11/23 15:57:09 by hatim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

void	skip_whitespace(char *line, int *i)
{
	while (is_space(line[*i]))
		(*i)++;
}

int	is_player(char c)
{
	return (c == 'N' || c == 'W' || c == 'E' || c == 'S');
}

int	is_valid_element(char c)
{
	return (c == '1' || c == '0' || is_player(c) || is_space(c));
}

int	ft_strstr_index(const char *big, const char *small)
{
	size_t	i;
	size_t	j;

	if (!big || !small)
		return (-1);
	if (*small == '\0')
		return (0);
	i = 0;
	while (big[i] != '\0')
	{
		j = 0;
		while (small[j] != '\0' && big[i + j] != '\0' && big[i + j] == small[j])
			j++;
		if (small[j] == '\0')
			return ((int)i);
		i++;
	}
	return (-1);
}
