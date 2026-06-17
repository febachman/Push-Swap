/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:59:51 by fbachman          #+#    #+#             */
/*   Updated: 2026/06/17 12:02:51 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num_digits_signed(long nbr, int base);

void	ft_print_decimal(int nbr, int *count)
{
	ft_putnbr_fd(nbr, 1);
	*count = *count + ft_num_digits_signed(nbr, 10);
}

int	ft_num_digits_unsigned(unsigned long nbr, int base);

static void	ft_put_unsignednbr_fd(unsigned int nbr, int fd)
{
	if (nbr > 9)
		ft_put_unsignednbr_fd(nbr / 10, fd);
	ft_putchar_fd((nbr % 10) + '0', fd);
}

void	ft_print_unsigned(unsigned int nbr, int *count)
{
	ft_put_unsignednbr_fd(nbr, 1);
	*count = *count + ft_num_digits_unsigned(nbr, 10);
}

int	ft_num_digits_signed(long nbr, int base)
{
	int	dig;

	dig = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		dig++;
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		nbr = nbr / base;
		dig++;
	}
	return (dig);
}

int	ft_num_digits_unsigned(unsigned long nbr, int base)
{
	int	dig;

	dig = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / base;
		dig++;
	}
	return (dig);
}
