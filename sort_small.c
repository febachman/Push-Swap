/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 09:17:43 by fbachman          #+#    #+#             */
/*   Updated: 2026/06/25 12:19:49 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack *st_a)
{
	int	top;
	int	mid;
	int	bot;

	if (st_a->size == 2 && (st_a->head->value > st_a->head->next->value))
		return (sa(st_a));
	if (st_a->size <= 2)
		return ;
	top = st_a->head->value;
	mid = st_a->head->next->value;
	bot = st_a->tail->value;
	if (top > mid && mid < bot && top < bot)
		sa(st_a);
	else if (top > mid && mid > bot && top > bot)
		(sa(st_a), ft_rrotate(st_a));
	else if (top > mid && mid < bot && top > bot)
		ft_rotate(st_a);
	else if (top < mid && mid > bot && top < bot)
		(ft_swap(st_a), ft_rotate(st_a));
	else if (top < mid && mid > bot && top > bot)
		ft_rrotate(st_a);
}
