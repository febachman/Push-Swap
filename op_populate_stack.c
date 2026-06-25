/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 08:08:49 by fbachman          #+#    #+#             */
/*   Updated: 2026/06/25 08:33:15 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack(t_stack *stack);
t_node	*ft_create_node(int value);

void	ft_populate_stack(t_stack *stack_a, int *parsed_array, int array_size)
{
	int		i;
	t_node	*new_node;

	i = 0;
	while (i < array_size)
	{
		new_node = ft_create_node(parsed_array[i]);
		if (!new_node)
			return ;
		ft_push_back(stack_a, new_node);
		i++;
	}
}

void	ft_init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

t_node	*ft_create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
