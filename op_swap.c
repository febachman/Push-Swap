/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-luc <made-luc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:28:04 by fbachman          #+#    #+#             */
/*   Updated: 2026/07/05 10:48:32 by made-luc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size < 2)
		return (0);
	node = ft_pop_node(stack, stack->head->next);
	if (!node)
		return (0);
	return (ft_push_front(stack, node));
}

void	ft_sa(t_stack *a)
{
	if (ft_swap(a))
	{
		if (a->bench)
		{
			a->bench->sa++;
			a->bench->total++;
		}
		write(1, "sa\n", 3);
	}
}

void	ft_sb(t_stack *b)
{
	if (ft_swap(b))
	{
		if (b->bench)
		{
			b->bench->sb++;
			b->bench->total++;
		}
		write(1, "sb\n", 3);
	}
}

void	ft_ss(t_stack *a, t_stack *b)
{
	if (a && a->size >= 2 && b && b->size >= 2)
	{
		ft_swap(a);
		ft_swap(b);
		if (a->bench)
		{
			a->bench->ss++;
			a->bench->total++;
		}
		write(1, "ss\n", 3);
	}
}
