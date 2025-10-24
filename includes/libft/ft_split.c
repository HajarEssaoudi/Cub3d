/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:04:32 by hqannouc          #+#    #+#             */
/*   Updated: 2025/10/24 20:52:04 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	n_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

// static char	**free_word(char **str, size_t i)
// {
// 	while (i > 0)
// 	{
// 		free(str[i]);
// 		i--;
// 	}
// 	free(str);
// 	return (NULL);
// }

static char	**ft_mal(size_t i, char c, const char *s, char **str)
{
	str[i] = (char *)gc_malloc(word_len(s, c) + 1);
	// if (!str[i])
	// 	return (free_word(str, i));
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char **)gc_malloc((n_words(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			ft_mal(i, c, s, str);
			j = 0;
			while (*s != c && *s != '\0')
				str[i][j++] = *s++;
			str[i++][j] = '\0';
		}
		else
			s++;
	}
	str[i] = NULL;
	return (str);
}
