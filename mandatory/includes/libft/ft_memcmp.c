/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:27:02 by hqannouc          #+#    #+#             */
/*   Updated: 2024/11/17 14:22:33 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
// #include <stdio.h>

// int main ()
// {
// 	int s1[] = {1, 2, 3};
// 	int s2[] = {1, 2, 3};
// 	if (ft_memcmp(s1, s2, 3 * sizeof(int)) > 0)
// 		printf ("s1 > s2\n");
// 	else if(ft_memcmp(s1, s2, 3 * sizeof(int)) < 0)
// 		printf ("s2 > s1\n");
// 	else
// 		printf ("s2 = s1\n");
// }
