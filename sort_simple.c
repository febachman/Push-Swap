/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:30:05 by fbachman          #+#    #+#             */
/*   Updated: 2026/07/01 16:04:10 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bubble_sort(t_stack *a)
{
	int	i;
	int	j;
	int	size;

	if (!a || a->size < 2)
		return ;
	size = a->size;
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (a->head->value > a->head->next->value)
				ft_sa(a);
			ft_ra(a);
			j++;
		}
		ft_ra(a);
		i++;
	}
}
