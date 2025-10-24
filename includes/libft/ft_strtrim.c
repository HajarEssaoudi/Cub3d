/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:00:59 by hqannouc          #+#    #+#             */
/*   Updated: 2024/11/17 21:59:08 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_comp(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	i = 0;
	while (s1[start] != '\0' && ft_comp(s1[start], set))
		start++;
	while (end > start && ft_comp(s1[end - 1], set))
		end--;
	trim = (char *) malloc((end - start + 1) * sizeof(char));
	if (!trim)
		return (NULL);
	while (start < end)
	{
		trim[i++] = s1[start++];
	}
	trim[i] = '\0';
	return (trim);
}
// #include <stdio.h>
// int main ()
// {
// 	printf("%s\n", ft_strtrim("      Na3ima sami7   ", " "));
// }