/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:25:30 by hqannouc          #+#    #+#             */
/*   Updated: 2025/10/24 20:58:33 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup_gnl(char const *s)
{
	size_t	len;
	size_t	i;
	char	*dup;

	i = 0;
	len = ft_strlen(s);
	dup = (char *) malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*ret;

	i = 0;
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	len = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *) malloc(len + 1);
	if (!ret)
		return (NULL);
	while (*s1 != '\0')
	{
		ret[i++] = *s1;
		s1++;
	}
	while (*s2 != '\0')
	{
		ret[i++] = *s2;
		s2++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_substr_gnl(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*sub;

	i = 0;
	if (str == NULL)
		return (NULL);
	slen = ft_strlen(str);
	if (start >= slen)
		return (ft_strdup_gnl(""));
	if (len > slen - start)
		len = slen - start;
	sub = (char *) malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len && str[start] != '\0')
		sub[i++] = str[start++];
	sub[i] = '\0';
	return (sub);
}

char	*ft_strchr_gnl(char const *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
