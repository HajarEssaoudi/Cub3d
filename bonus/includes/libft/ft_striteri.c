/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:27:14 by hqannouc          #+#    #+#             */
/*   Updated: 2024/11/17 21:41:12 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
// #include <stdio.h>

// void	to_upperc(unsigned int i, char *c)
// {
// 	if (*c >= 'a' && *c <= 'z')
// 		*c = *c - 32;
// }
// int main()
// {
// 	char str[] = "hello world!";
// 	ft_striteri(str, to_upperc);
// 	printf("%s\n", str);
// 	return 0;
// }