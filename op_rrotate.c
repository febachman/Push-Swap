/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-luc <made-luc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:28:02 by fbachman          #+#    #+#             */
/*   Updated: 2026/07/05 10:55:09 by made-luc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rrotate(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size < 2)
		return (0);
	node = ft_pop_node(stack, stack->tail);
	if (!node)
		return (0);
	return (ft_push_front(stack, node));
}

void	ft_rra(t_stack *a)
{
	if (ft_rrotate(a))
	{
		if (a->bench)
		{
			a->bench->rra++;
			a->bench->total++;
		}
		write(1, "rra\n", 4);
	}
}

void	ft_rrb(t_stack *b)
{
	if (ft_rrotate(b))
	{
		if (b->bench)
		{
			b->bench->rrb++;
			b->bench->total++;
		}
		write(1, "rrb\n", 4);
	}
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	if (a && a->size >= 2 && b && b->size >= 2)
	{
		ft_rrotate(a);
		ft_rrotate(b);
		if (a->bench)
		{
			a->bench->rrr++;
			a->bench->total++;
		}
		write(1, "rrr\n", 4);
	}
}
