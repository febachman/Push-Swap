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

static void	print_adaptive_complexity(double disorder)
{
	if (disorder < 0.2)
		ft_putstr_fd("adaptive / O(n^2)\n", 2);
	else if (disorder < 0.5)
		ft_putstr_fd("adaptive / O(n sqrt(n))\n", 2);
	else
		ft_putstr_fd("adaptive / O(n log n)\n", 2);
}

static void	print_strategy(t_parsing *parsing, double disorder)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (parsing->strategy == SIMPLE)
		ft_putstr_fd("simple / O(n^2)\n", 2);
	else if (parsing->strategy == MEDIUM)
		ft_putstr_fd("medium / O(n sqrt(n))\n", 2);
	else if (parsing->strategy == COMPLEX)
		ft_putstr_fd("complex / O(n log n)\n", 2);
	else
		print_adaptive_complexity(disorder);
}

static void	print_operations(t_bench *bench)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd("  sb: ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd("  ss: ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd("  pa: ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd("  pb: ", 2);
	ft_putnbr_fd(bench->pb, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd("  rb: ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd("  rr: ", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd("  rra: ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd("  rrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd("  rrr: ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	ft_putstr_fd("\n", 2);
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
	print_strategy(parsing, disorder);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(bench->total, 2);
	ft_putstr_fd("\n", 2);
	print_operations(bench);
}
