/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:06:41 by made-luc          #+#    #+#             */
/*   Updated: 2026/07/04 11:12:25 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_args(int argc, char **argv, t_stack *a, t_parsing *parsing)
{
	int	i;
	int	flag_result;

	i = 1;
	while (i < argc)
	{
		if (!argv[i] || argv[i][0] == '\0')
			return (1);
		flag_result = parse_flag(argv[i], parsing);
		if (flag_result == -1)
			return (1);
		if (flag_result == 0)
		{
			if (parse_number_token(argv[i], a))
				return (1);
			parsing->seen_number = true;
		}
		i++;
	}
	if (parsing->seen_number == false)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_parsing	parsing;

	if (argc < 2)
		return (0);
	ft_init_stack(&a);
	init_parsing_config(&parsing);
	if (parse_args(argc, argv, &a, &parsing))
	{
		ft_clear_stack(&a);
		write(2, "Error\n", 6);
		return (1);
	}
	/*
	int		apply_strategy(t_parsing *parsing, t_stack *a);

	*/
	ft_clear_stack(&a);
	return (0);
}

//int		apply_strategy(t_parsing *parsing, t_stack *a);