/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:06:41 by made-luc          #+#    #+#             */
/*   Updated: 2026/07/07 07:53:20 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **tokens)
{
	int	i;

	i = 0;
	if (!tokens)
		return ;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	parse_split_tokens(char **tokens, t_stack *a, t_parsing *parsing)
{
	int	i;

	i = 0;
	if (!tokens || !tokens[0])
		return (1);
	while (tokens[i])
	{
		if (parse_number_token(tokens[i], a))
			return (1);
		parsing->seen_number = true;
		i++;
	}
	return (0);
}

static int	parse_arg_nmb(char *arg, t_stack *a, t_parsing *parsing)
{
	char	**tokens;

	tokens = ft_split(arg, ' ');
	if (parse_split_tokens(tokens, a, parsing))
	{
		free_split(tokens);
		return (1);
	}
	free_split(tokens);
	return (0);
}

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
		if (flag_result == 0 && parse_arg_nmb(argv[i], a, parsing))
			return (1);
		i++;
	}
	if (parsing->seen_number == false)
		return (1);
	return (0);
}
