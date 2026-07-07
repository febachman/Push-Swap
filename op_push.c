/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-luc <made-luc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:27:57 by fbachman          #+#    #+#             */
/*   Updated: 2026/07/05 11:23:29 by made-luc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_stack *dest, t_stack *src)
{
	t_node	*node;

	if (!src || src->size == 0 || !dest)
		return (0);
	node = ft_pop_node(src, src->head);
	if (!node)
		return (0);
	return (ft_push_front(dest, node));
}

void	ft_pa(t_stack *a, t_stack *b)
{
	if (ft_push(a, b))
	{	
		if (a->bench)
		{
			a->bench->pa++;
			a->bench->total++;
		}
		write(1, "pa\n", 3);
	}
}

void	ft_pb(t_stack *a, t_stack *b)
{
	if (ft_push(b, a))
	{
		if (b->bench)
		{
			b->bench->pb++;
			b->bench->total++;
		}
		write(1, "pb\n", 3);
	}
}
