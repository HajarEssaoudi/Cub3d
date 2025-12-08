/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:10:36 by hqannouc          #+#    #+#             */
/*   Updated: 2025/10/24 18:49:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	ret = (char *) gc_malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (s[i] != '\0')
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
// #include <stdio.h>

// char	to_upperc(unsigned int i, char c)
// {
// 	if (c >= 'a' && c <= 'z')
// 		c = c - 32;
// 	return (c);
// }
// int main()
// {
// 	char str[] = "hello world!";
// 	char *l = ft_strmapi(str, to_upperc);
// 	printf("%s\n", l);
// 	return 0;
// }