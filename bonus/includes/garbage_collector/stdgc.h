/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdgc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:24:23 by hes-saou          #+#    #+#             */
/*   Updated: 2025/10/24 18:40:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDGC_H
#define STDGC_H

#include <stdlib.h>
#include <stddef.h>
#include "../libft/libft.h"

typedef struct s_block
{
	void *ptr;
	size_t size;
	int	 used;
	struct s_block *next;
} t_block;

typedef struct s_gc
{
	t_block *head;
} t_gc;

void *gc_malloc(size_t size);
void gc_free_all(void);
void *gc_calloc(size_t count, size_t size);
#endif