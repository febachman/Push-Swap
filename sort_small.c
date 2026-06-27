/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 09:17:43 by fbachman          #+#    #+#             */
/*   Updated: 2026/06/26 18:48:16 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	if (a->size == 2 && (a->head->value > a->head->next->value))
		return (ft_sa(a));
	if (a->size <= 2)
		return ;
	top = a->head->value;
	mid = a->head->next->value;
	bot = a->tail->value;
	if (top > mid && mid < bot && top < bot)
		ft_sa(a);
	else if (top > mid && mid > bot && top > bot)
		(ft_sa(a), ft_rra(a));
	else if (top > mid && mid < bot && top > bot)
		ft_ra(a);
	else if (top < mid && mid > bot && top < bot)
		(ft_sa(a), ft_ra(a));
	else if (top < mid && mid > bot && top > bot)
		ft_rra(a);
}

int	ft_find_min(t_stack *stack);

void	ft_sort_four(t_stack *a, t_stack *b)
{
	int	min_position;

	min_position = ft_find_min(a);
	if (min_position == 1)
		ft_ra(a);
	else if (min_position == 2)
	{
		ft_ra(a);
		ft_ra(a);
	}
	else if (min_position == 3)
		ft_rra(a);
	ft_pb(a, b);
	ft_sort_three(a);
	ft_pa(a, b);
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	int	min_position;

	min_position = ft_find_min(a);
	if (min_position == 1)
		ft_ra(a);
	else if (min_position == 2)
	{
		ft_ra(a);
		ft_ra(a);
	}
	else if (min_position == 3)
	{
		ft_rra(a);
		ft_rra(a);
	}
	else if (min_position == 4)
		ft_rra(a);
	ft_pb(a, b);
	ft_sort_four(a, b);
	ft_pa(a, b);
}

int	ft_find_min(t_stack *stack)
{
	t_node	*cur;
	int		min_val;
	int		min_index;
	int		cur_position;

	if (!stack || !stack->head)
		return (-1);
	cur = stack->head;
	min_val = cur->value;
	min_index = 0;
	cur_position = 0;
	while (cur != NULL)
	{
		if (cur->value < min_val)
		{
			min_val = cur->value;
			min_index = cur_position;
		}
		cur = cur->next;
		cur_position++;
	}
	return (min_index);
}
