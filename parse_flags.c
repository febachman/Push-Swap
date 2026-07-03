/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:06:41 by made-luc          #+#    #+#             */
/*   Updated: 2026/07/03 15:08:04 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_parsing_config(t_parsing *parsing)
{
	parsing->strategy = ADAPTIVE;
	parsing->bench = false;
	parsing->has_strategy = false;
	parsing->seen_number = false;
}

int	parse_strategy_flag(char *arg, t_parsing *parsing)
{
	if (ft_strncmp(arg, "--simple", 8) == 0)
	{
		parsing->strategy = SIMPLE;
		return (1);
	}
	else if (ft_strncmp(arg, "--medium", 8) == 0)
	{
		parsing->strategy = MEDIUM;
		return (1);
	}
	else if (ft_strncmp(arg, "--complex", 9) == 0)
	{
		parsing->strategy = COMPLEX;
		return (1);
	}
	else if (ft_strncmp(arg, "--adaptive", 10) == 0)
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
	if (ft_strncmp(arg, "--bench", 7) == 0)
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
