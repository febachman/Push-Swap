/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-luc <made-luc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:02:11 by made-luc          #+#    #+#             */
/*   Updated: 2026/07/05 11:27:19 by made-luc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_error_stacks(t_stack *a, t_stack *b)
{
	ft_clear_stack(a);
	ft_clear_stack(b);
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_parsing	parsing;
	t_bench		bench;
	double		disorder;

	if (argc < 2)
		return (0);
	ft_init_stack(&a);
	ft_init_stack(&b);
	init_parsing_config(&parsing);
	init_bench(&bench);
	a.bench = &bench;
	b.bench = &bench;
	if (parse_args(argc, argv, &a, &parsing))
		return (ft_error_stacks(&a, &b));
	disorder = ft_compute_disorder(&a);
	if (apply_strategy(&parsing, &a, &b, disorder))
		return (ft_error_stacks(&a, &b));
	if (parsing.bench)
		print_benchmark(&parsing, &bench, disorder);
	ft_clear_stack(&a);
	ft_clear_stack(&b);
	return (0);
}
