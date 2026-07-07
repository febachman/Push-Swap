/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 07:52:22 by fbachman          #+#    #+#             */
/*   Updated: 2026/07/07 07:53:10 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_adaptive(t_stack *a, t_stack *b, double disorder)
{
	if (disorder < 0.2)
		ft_bubble_sort(a);
	else if (disorder < 0.5)
		ft_chunk_sort(a, b);
	else
		ft_chunklog_sort(a, b);
}

int	apply_strat(t_parsing *parse, t_stack *a, t_stack *b, double disorder)
{
	if (!parse || !a || !b)
		return (1);
	if (a->size <= 1)
		return (0);
	if (a->size <= 3)
		ft_sort_three(a);
	else if (a->size == 4)
		ft_sort_four(a, b);
	else if (a->size == 5)
		ft_sort_five(a, b);
	else if (parse->strategy == SIMPLE)
		ft_bubble_sort(a);
	else if (parse->strategy == MEDIUM)
		ft_chunk_sort(a, b);
	else if (parse->strategy == ADAPTIVE)
		apply_adaptive(a, b, disorder);
	else if (parse->strategy == COMPLEX)
		ft_chunklog_sort(a, b);
	else
		return (1);
	return (0);
}
