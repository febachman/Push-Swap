/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-luc <made-luc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:44:02 by fbachman          #+#    #+#             */
/*   Updated: 2026/07/06 17:39:32 by made-luc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_log2(int n)
{
	int	log;

	log = 0;
	while (n >>= 1)
		log++;
	return (log);
}

#include <stdio.h>
void	ft_chunklog_sort(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	total;

	total = a->size;
	chunk_size = (total / ft_log2(total)) * 6 / 10;
	if (chunk_size <= 0)
		chunk_size = 1;
	ft_phase_one_complex(a, b, chunk_size);
	ft_phase_two(a, b);
}

void	ft_phase_one_complex(t_stack *a, t_stack *b, int chunk_size)
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
