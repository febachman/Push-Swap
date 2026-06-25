/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 09:24:17 by fbachman          #+#    #+#             */
/*   Updated: 2026/06/18 10:12:34 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_front(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return (0);
	if (stack->size == 0)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		node->next = stack->head;
		stack->head->prev = node;
		stack->head = node;
	}
	stack->size++;
	return (1);
}
