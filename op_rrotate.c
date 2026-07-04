/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:28:02 by fbachman          #+#    #+#             */
/*   Updated: 2026/06/27 11:53:25 by fbachman         ###   ########.fr       */
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
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *b)
{
	if (ft_rrotate(b))
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	if (a && a->size >= 2 && b && b->size >= 2)
	{
		ft_rrotate(a);
		ft_rrotate(b);
		write(1, "rrr\n", 4);
	}
}
