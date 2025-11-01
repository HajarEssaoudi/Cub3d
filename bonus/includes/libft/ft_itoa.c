/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:51:58 by hqannouc          #+#    #+#             */
/*   Updated: 2024/11/17 12:38:43 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ft_len(int n)
{
	size_t	i;

	i = 0;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		i++;
	}
	if (n < 0)
		return (i + 2);
	return (i + 1);
}

static void	ft_norm(int *n, char *ret, int *r)
{
	if (*n == -2147483648)
	{
		ret[*r - 1] = '8';
		*n = *n / 10;
		*r = *r - 1;
	}
	if (*n < 0)
	{
		*n = -(*n);
		ret[0] = '-';
	}
}

static char	ft_getnbr(int n)
{
	int	g;

	g = n % 10;
	return (g + 48);
}

char	*ft_itoa(int n)
{
	char	*ret;
	size_t	i;
	int		r;

	r = ft_len(n);
	i = 1;
	ret = (char *)malloc((r + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[r] = '\0';
	if (n == 0)
	{
		ret[0] = '0';
		return (ret);
	}
	if (n < 0)
		ft_norm(&n, ret, &r);
	while (n != 0)
	{
		ret[r - i] = ft_getnbr(n);
		n = n / 10;
		i++;
	}
	return (ret);
}
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(-21442));
// 	printf("%s\n", ft_itoa(-2147483648));
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(1442));
// 	printf("%s\n", ft_itoa('a'));
// }
