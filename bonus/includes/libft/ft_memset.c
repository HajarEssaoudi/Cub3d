/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:31:47 by hqannouc          #+#    #+#             */
/*   Updated: 2025/04/09 21:57:53 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*p;
	unsigned char	byte_value;
	size_t			i;

	p = (unsigned char *)ptr;
	byte_value = (unsigned char)value;
	i = 0;
	while (i < num)
	{
		p[i] = byte_value;
		i++;
	}
	return (ptr);
}
