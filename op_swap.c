/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:28:04 by fbachman          #+#    #+#             */
/*   Updated: 2026/06/19 09:23:40 by fbachman         ###   ########.fr       */
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

void	sa(t_stack *a)
{
	if (ft_swap(a))
		write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	if (ft_swap(b))
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	int	swap_a;
	int	swap_b;

	swap_a = ft_swap(a);
	swap_b = ft_swap(b);
	if (swap_a || swap_b)
		write(1, "ss\n", 3);
}
