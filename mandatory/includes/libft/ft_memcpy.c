/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:40:27 by hqannouc          #+#    #+#             */
/*   Updated: 2024/11/17 15:21:17 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (src == NULL && dest == NULL)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < size)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
// #include <stdio.h>
// int main()
// {
// 	int d[20];
// 	int s[] = {1, 2, 3, 7, 6, 5};
// 	int n = 5;
// 	int *m = (int *)ft_memcpy(d, s, n * sizeof(int));
// 	int i = 0;

// 	while (i < n)
// 	{
// 		printf("%d\n", m[i]);
// 		i++;
// 	}
// }
