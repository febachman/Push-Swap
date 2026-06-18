/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 08:55:59 by fbachman          #+#    #+#             */
/*   Updated: 2026/06/18 09:48:23 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_pop_node(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return (NULL);
	if (node == stack->head)
		stack->head = node->next;
	if (node == stack->tail)
		stack->tail = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}
