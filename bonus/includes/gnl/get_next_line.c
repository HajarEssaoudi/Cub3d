/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatim <hqannouc@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:14:06 by hqannouc          #+#    #+#             */
/*   Updated: 2025/11/29 12:22:40 by hatim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_remainder(char *remainder)
{
	char	*rem;
	size_t	i;

	if (!remainder)
		return (NULL);
	i = 0;
	while (remainder[i] != '\0' && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	if (remainder[i] == '\0')
	{
		free(remainder);
		return (NULL);
	}
	rem = ft_strdup_gnl(remainder + i);
	if (!rem)
		return (NULL);
	free(remainder);
	return (rem);
}

char	*extract_line(char *remainder)
{
	size_t	i;
	char	*line;

	if (!remainder || !*remainder)
		return (NULL);
	i = 0;
	while (remainder[i] != '\0' && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i > 0)
	{
		i--;
		line[i] = remainder[i];
	}
	return (line);
}

char	*read_buffer(int fd, char *remainder)
{
	char	*buff;
	char	*temp;
	ssize_t	r;

	buff = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	r = 1;
	while (r > 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r < 0)
		{
			free(buff);
			free(remainder);
			return (NULL);
		}
		if (r == 0)
			break ;
		buff[r] = '\0';
		temp = remainder;
		remainder = ft_strjoin_gnl(temp, buff);
		free(temp);
	}
	return (free(buff), remainder);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder;

	if (fd == -1)
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_buffer(fd, remainder);
	if (!remainder)
		return (NULL);
	line = extract_line(remainder);
	remainder = new_remainder(remainder);
	return (line);
}
