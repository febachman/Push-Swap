/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:06:41 by made-luc          #+#    #+#             */
/*   Updated: 2026/07/01 16:23:02 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TODO: LIDAR COM CASO (./push_swap --bench --bench 3 2 1)

void	init_parsing_config(t_parsing *parsing)
{
	parsing->strategy = ADAPTIVE;
	parsing->bench = false;
	parsing->has_strategy = false;
	parsing->seen_number = false;
}

int	parse_strategy_flag(char *arg, t_parsing *parsing)
{
	if (ft_strcmp(arg, "--simple") == 0)
	{
		parsing->strategy = SIMPLE;
		return (1);
	}
	else if (ft_strcmp(arg, "--medium") == 0)
	{
		parsing->strategy = MEDIUM;
		return (1);
	}
	else if (ft_strcmp(arg, "--complex") == 0)
	{
		parsing->strategy = COMPLEX;
		return (1);
	}
	else if (ft_strcmp(arg, "--adaptive") == 0)
	{
		parsing->strategy = ADAPTIVE;
		return (1);
	}
	if (arg[0] == '-' && arg[1] == '-')
		return (-1);
	return (0);
}

int	parse_bench_flag(char *arg, t_parsing *parsing)
{
	if (ft_strcmp(arg, "--bench") == 0)
	{
		parsing->bench = true;
		return (1);
	}
	return (0);
}

int	parse_flag(char *arg, t_parsing *parsing)
{
	int	result;

	if (parse_bench_flag(arg, parsing))
		return (1);
	result = parse_strategy_flag(arg, parsing);
	if (result == 1)
	{
		if (parsing->has_strategy == true)
			return (-1);
		parsing->has_strategy = true;
		return (1);
	}
	if (result == -1)
		return (-1);
	return (0);
}
