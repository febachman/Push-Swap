/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 10:47:57 by fbachman          #+#    #+#             */
/*   Updated: 2026/06/03 10:14:52 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dispatcher(char c, va_list tokens, int *count);

int	ft_printf(const char *format, ...)
{
	va_list	tokens;
	int		i;
	int		count;

	va_start(tokens, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			ft_dispatcher(format[i], tokens, &count);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end(tokens);
	return (count);
}

void	ft_dispatcher(char c, va_list tokens, int *count)
{
	if (c == 'c')
		ft_print_char((char)va_arg(tokens, int), count);
	else if (c == 's')
		ft_print_str(va_arg(tokens, char *), count);
	else if (c == 'd' || c == 'i')
		ft_print_decimal(va_arg(tokens, int), count);
	else if (c == 'u')
		ft_print_unsigned(va_arg(tokens, unsigned int), count);
	else if (c == 'x' || c == 'X')
		ft_print_hex(va_arg(tokens, unsigned int), c, count);
	else if (c == 'p')
		ft_print_ptr(va_arg(tokens, unsigned long), count);
	else if (c == '%')
		ft_print_char('%', count);
}
