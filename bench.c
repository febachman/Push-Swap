/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-luc <made-luc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:06:41 by made-luc          #+#    #+#             */
/*   Updated: 2026/07/05 11:42:05 by made-luc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_bench(t_bench *bench)
{
	bench->total = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

static void	print_bench_line(char *name, int value)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(value, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_operations(t_bench *bench)
{
	print_bench_line("sa", bench->sa);
	print_bench_line("sb", bench->sb);
	print_bench_line("ss", bench->ss);
	print_bench_line("pa", bench->pa);
	print_bench_line("pb", bench->pb);
	print_bench_line("ra", bench->ra);
	print_bench_line("rb", bench->rb);
	print_bench_line("rr", bench->rr);
	print_bench_line("rra", bench->rra);
	print_bench_line("rrb", bench->rrb);
	print_bench_line("rrr", bench->rrr);
}

void	print_benchmark(t_parsing *parsing, t_bench *bench, double disorder)
{
	int	percent;

	if (!parsing || !bench)
		return ;
	percent = (int)(disorder * 10000);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(percent / 100, 2);
	ft_putstr_fd(".", 2);
	if (percent % 100 < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(percent % 100, 2);
	ft_putstr_fd("%\n", 2);
	print_bench_line("total", bench->total);
	print_operations(bench);
}
