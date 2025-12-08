/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:46:58 by hqannouc          #+#    #+#             */
/*   Updated: 2024/11/17 13:48:13 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
// #include <stdio.h>

// int main()
// {
// 	int i = 0;
// 	int a[] = {1, 3, 65, 4, 7, 8 , 56};
// 	int *s = (int *)ft_memchr(a, 4, 3 * sizeof(int));
// 	if (s == NULL)
// 	{
// 		printf("not found\n");
// 		return (0);
// 	}
// 	while (i < 7 - (s - a))
// 	{
// 		printf ("%d\n", s[i]);
// 		i++;
// 	}
// }
