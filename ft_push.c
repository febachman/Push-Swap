/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:27:57 by fbachman          #+#    #+#             */
/*   Updated: 2026/06/18 11:08:15 by fbachman         ###   ########.fr       */
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
