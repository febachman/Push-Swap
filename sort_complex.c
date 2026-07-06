/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:44:02 by fbachman          #+#    #+#             */
/*   Updated: 2026/07/06 13:28:43 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_index(t_stack *a, t_stack *b, int value);
int	ft_max_position(t_stack	*stack);

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

chunk_size = (total_size / log2(total_size)) * multiplier;

// Take the current size of the sub-stack you are operating on (current_size).

// Find two pivots:

// Pivot 1: The element at the 33rd percentile (index current_size / 3).

// Pivot 2: The element at the 66th percentile (index current_size * 2 / 3)

int	ft_log2(int n)
{
	int log;

	log = 0;
	while (n >>= 1)
		log++;
	return (log);
}

void	ft_complex_sort(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	total;

	total = a->size;
	chunk_size = (total / ft_log2(total)) * 13 / 10;
	if (chunk_size <= 0)
		chunk_size = 1;
	ft_phase_one_complex(a, b, chunk_size);
	ft_phase_two(a, b);
}

void    ft_phase_one_complex(t_stack *a, t_stack *b, int chunk_size)
{
    int i;
    int current_index;

    i = 0;
    while (a->size > 0)
    {
        current_index = ft_get_index(a, b, a->head->value);
        
        // Lower half of the current logarithmic chunk (Quick Sort lower partition)
        if (current_index <= i)
        {
            ft_pb(a, b);
            ft_rb(b);
            i++;
        }
        // Upper half of the current logarithmic chunk (Quick Sort upper partition)
        else if (current_index <= (i + chunk_size))
        {
            ft_pb(a, b);
            i++;
        }
        // If it belongs to a completely different recursive tree branch, leave it for now
        else
            ft_ra(a);
    }
}
