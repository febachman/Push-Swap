/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-luc <made-luc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:02:11 by made-luc          #+#    #+#             */
/*   Updated: 2026/07/04 12:25:22 by made-luc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	ft_is_sorted(t_stack *a)
// {
// 	t_node	*cur;

// 	if (!a || !a->head)
// 		return (1);
// 	cur = a->head;
// 	while (cur->next)
// 	{
// 		if (cur->value > cur->next->value)
// 			return (0);
// 		cur = cur->next;
// 	}
// 	return (1);
// }

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_parsing	parsing;

	if (argc < 2)
		return (0);
	ft_init_stack(&a);
	ft_init_stack(&b);
	init_parsing_config(&parsing);
	if (parse_args(argc, argv, &a, &parsing))
	{
		ft_clear_stack(&a);
		write(2, "Error\n", 6);
		return (1);
	}
	apply_strategy(&parsing, &a, &b);
    // if (ft_is_sorted(&a) && b.size == 0)
	//     write(2, "OK\n", 3);
    // else
	//     write(2, "KO\n", 3);
	return (0);
}
