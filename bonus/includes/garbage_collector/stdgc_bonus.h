/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdgc_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:24:23 by hes-saou          #+#    #+#             */
/*   Updated: 2025/12/08 16:53:07 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDGC_BONUS_H
# define STDGC_BONUS_H

# include <stdlib.h>
# include <stddef.h>

typedef struct s_block
{
	void			*ptr;
	size_t			size;
	struct s_block	*next;
}	t_block;

typedef struct s_gc
{
	t_block	*head;
}	t_gc;

void	*gc_malloc(size_t size);
void	gc_free_all(void);

#endif