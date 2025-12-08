/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:13:24 by hqannouc          #+#    #+#             */
/*   Updated: 2025/10/24 18:49:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	total_len(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	return (i + j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	t;
	char	*join;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	t = total_len(s1, s2);
	join = (char *) gc_malloc((t + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (*s1 != '\0')
	{
		join[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		join[i] = *s2;
		i++;
		s2++;
	}
	join[i] = '\0';
	return (join);
}
