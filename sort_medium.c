/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:19:22 by fbachman          #+#    #+#             */
/*   Updated: 2026/07/03 14:44:33 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_phase_one(t_stack *a, t_stack *b, int chunk_size);
void	ft_phase_two(t_stack *a, t_stack *b);

void	ft_chunk_sort(t_stack *a, t_stack *b)
{
	int	chunk_size;

	if (a->size <= 100)
		chunk_size = 18;
	else
		chunk_size = 45;
	ft_phase_one(a, b, chunk_size);
	ft_phase_two(a, b);
}

int	ft_get_index(t_stack *a, t_stack *b, int value)
{
	t_node	*compare;
	int		rank;

	rank = 0;
	if (a && a->head)
	{
		compare = a->head;
		while (compare != NULL)
		{
			if (value > compare->value)
				rank++;
			compare = compare->next;
		}
	}
	if (b && b->head)
	{
		compare = b->head;
		while (compare != NULL)
		{
			if (value > compare->value)
				rank++;
			compare = compare->next;
		}
	}
	return (rank);
}

int	ft_max_position(t_stack	*stack)
{
	t_node	*cur;
	int		max_rank;
	int		cur_rank;
	int		max_pos;
	int		cur_pos;

	if (!stack || !stack->head)
		return (-1);
	cur = stack->head;
	max_rank = ft_get_index(NULL, stack, cur->value);
	max_pos = 0;
	cur_pos = 0;
	while (cur != NULL)
	{
		cur_rank = ft_get_index(NULL, stack, cur->value);
		if (cur_rank > max_rank)
		{
			max_rank = cur_rank;
			max_pos = cur_pos;
		}
		cur = cur->next;
		cur_pos++;
	}
	return (max_pos);
}

void	ft_phase_one(t_stack *a, t_stack *b, int chunk_size)
{
	int	i;
	int	current_index;

	i = 0;
	while (a->size > 0)
	{
		current_index = ft_get_index(a, b, a->head->value);
		if (current_index <= i)
		{
			ft_pb(a, b);
			ft_rb(b);
			i++;
		}
		else if (current_index <= (i + chunk_size))
		{
			ft_pb(a, b);
			i++;
		}
		else
			ft_ra(a);
	}
}

void	ft_phase_two(t_stack *a, t_stack *b)
{
	int	max_pos;

	while (b->size > 0)
	{
		max_pos = ft_max_position(b);
		if (max_pos <= b->size / 2)
		{
			while (max_pos-- > 0)
				ft_rb(b);
		}
		else
		{
			max_pos = b->size - max_pos;
			while (max_pos-- > 0)
				ft_rrb(b);
		}
		ft_pa(a, b);
	}
}
