/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:45:06 by hqannouc          #+#    #+#             */
/*   Updated: 2025/09/18 16:28:09 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *s, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*s == '\0')
		return ((char *)b);
	if (n == 0)
		return (NULL);
	while (b[i] != '\0' && i < n)
	{
		j = 0;
		while (s[j] != '\0' && (i + j) < n && b[i + j] == s[j])
		{
			j++;
		}
		if (s[j] == '\0')
			return ((char *)&b[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int main()
// {
// 	char *b = "Hello, Hatim";
// 	char *s = "ello";
// 	char *f = ft_strnstr(b, s, 8);
// 	printf("%s\n", &f);
// }
