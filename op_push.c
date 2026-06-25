/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:27:57 by fbachman          #+#    #+#             */
/*   Updated: 2026/06/19 09:21:20 by fbachman         ###   ########.fr       */
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

void	pa(t_stack *a, t_stack *b)
{
	if (ft_push(a, b))
		write(1, "pa\n", 3);
}

void	pb(t_stack *b, t_stack *a)
{
	if (ft_push(b, a))
		write(1, "pb\n", 3);
}
