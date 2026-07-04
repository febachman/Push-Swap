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

int	is_valid_number(char *token)
{
	int	i;

	i = 0;
	if (!token || token[0] == '\0')
		return (0);
	if (token[i] == '+' || token[i] == '-')
		i++;
	if (token[i] == '\0')
		return (0);
	while (token[i] != '\0')
	{
		if (!ft_isdigit(token[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_int_overflow(long num, int sign)
{
	if (sign > 0 && num > INT_MAX)
		return (1);
	if (sign < 0 && num > (long)INT_MAX + 1)
		return (1);
	return (0);
}

int	ft_atol_checked(char *str, int *out)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (!str || !out)
		return (1);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		if (is_int_overflow(num, sign))
			return (1);
		i++;
	}
	*out = (int)(num * sign);
	return (0);
}

int	ft_stack_has_value(t_stack *stack, int value)
{
	t_node	*cur;

	if (!stack)
		return (0);
	cur = stack->head;
	while (cur != NULL)
	{
		if (cur->value == value)
			return (1);
		cur = cur->next;
	}
	return (0);
}

int	parse_number_token(char *token, t_stack *stack)
{
	int		value;
	t_node	*node;

	if (!is_valid_number(token))
		return (1);
	if (ft_atol_checked(token, &value))
		return (1);
	if (ft_stack_has_value(stack, value))
		return (1);
	node = ft_create_node(value);
	if (!node)
		return (1);
	if (!ft_push_back(stack, node))
	{
		free(node);
		return (1);
	}
	return (0);
}
