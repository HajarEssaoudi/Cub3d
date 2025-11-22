/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdgc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:24:23 by hes-saou          #+#    #+#             */
/*   Updated: 2025/11/08 12:15:41 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdgc.h"

static t_gc *get_gc(void)
{
    static t_gc gc = {NULL};

    return (&gc);
}

void *gc_malloc(size_t size)
{
    char *ptr;
    t_block *block;
    t_gc *gc;

    gc = get_gc();
    ptr = malloc(size);
    if (ptr == NULL)
        return (NULL);
    block = malloc(sizeof(t_block));
    if (block == NULL)
    {
        free(ptr);
        return (NULL);
    }
    block->ptr = ptr;
    block->size = size;
    block->next = gc->head;
    gc->head = block;
    return (ptr);
}

void gc_free_all(void)
{
    t_block *current;
    t_block *next;
    t_gc *gc;

    gc = get_gc();
    current = gc->head;
    while (current)
    {
        next = current->next;
        free(current->ptr);
        free(current);
        current = next;
    }
    gc->head = NULL;
}
