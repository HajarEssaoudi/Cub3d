/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:42:13 by hqannouc          #+#    #+#             */
/*   Updated: 2025/10/24 20:58:18 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_len;
	char	*sub;

	if (str == NULL)
		return (NULL);
	str_len = 0;
	i = 0;
	while (str[str_len] != '\0')
		str_len++;
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	sub = (char *) gc_malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len && str[start] != '\0')
		sub[i++] = str[start++];
	sub[i] = '\0';
	return (sub);
}
