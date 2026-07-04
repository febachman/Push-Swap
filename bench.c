/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-luc <made-luc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:06:41 by made-luc          #+#    #+#             */
/*   Updated: 2026/07/03 09:59:46 by made-luc         ###   ########.fr       */
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
	ft_putstr_fd("[bench] total: ", 2);
	ft_putnbr_fd(bench->total, 2);
	ft_putstr_fd("\n", 2);
}

// operação em A       -> usa a->bench
// operação em B       -> usa b->bench
// operação nos dois   -> usa a->bench
// push entre A e B    -> usa a->bench