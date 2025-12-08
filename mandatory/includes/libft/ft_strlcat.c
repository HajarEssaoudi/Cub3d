/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:57:37 by hqannouc          #+#    #+#             */
/*   Updated: 2025/10/24 18:49:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t d_size)
{
	size_t	s_len;
	size_t	d_len;
	size_t	i;

	if ((!dest || !src) && d_size == 0)
		return (0);
	s_len = ft_strlen(src);
	d_len = ft_strlen(dest);
	if (d_size == 0)
		return (s_len);
	if (d_size <= d_len)
		d_len = d_size;
	i = 0;
	while ((d_len + i) < d_size - 1 && src[i] != '\0')
	{
		dest[d_len + i] = src[i];
		i++;
	}
	if (d_len + i < d_size)
		dest[d_len + i] = '\0';
	return (d_len + s_len);
}
