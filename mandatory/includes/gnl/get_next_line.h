/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:25:23 by hqannouc          #+#    #+#             */
/*   Updated: 2025/12/08 18:15:14 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../garbage_collector/stdgc.h"

size_t	ft_strlen(char const*s);
char	*ft_strdup_gnl(char const *s);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_substr_gnl(char const *str, unsigned int start, size_t len);
char	*ft_strchr_gnl(char const *s, int c);
char	*get_next_line(int fd);

#endif