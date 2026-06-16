/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:59:46 by fbachman          #+#    #+#             */
/*   Updated: 2026/06/03 10:01:32 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char c, int *count)
{
	ft_putchar_fd(c, 1);
	(*count)++;
}

void	ft_print_str(char *str, int *count)
{
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	*count = *count + ft_strlen(str);
}
