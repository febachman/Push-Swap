/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-luc <made-luc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:27:59 by fbachman          #+#    #+#             */
/*   Updated: 2026/07/05 10:56:18 by made-luc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size < 2)
		return (0);
	node = ft_pop_node(stack, stack->head);
	if (!node)
		return (0);
	return (ft_push_back(stack, node));
}

void	ft_ra(t_stack *a)
{
	if (ft_rotate(a))
	{
		if (a->bench)
		{
			a->bench->ra++;
			a->bench->total++;
		}
		write(1, "ra\n", 3);
	}
}

void	ft_rb(t_stack *b)
{
	if (ft_rotate(b))
	{
		if (b->bench)
		{
			b->bench->rb++;
			b->bench->total++;
		}
		write(1, "rb\n", 3);
	}
}

void	ft_rr(t_stack *a, t_stack *b)
{
	if (a && a->size >= 2 && b && b->size >= 2)
	{
		ft_rotate(a);
		ft_rotate(b);
		if (a->bench)
		{
			a->bench->rr++;
			a->bench->total++;
		}
		write(1, "rr\n", 3);
	}
}
