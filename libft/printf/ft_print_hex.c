/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:59:48 by fbachman          #+#    #+#             */
/*   Updated: 2026/06/17 12:02:45 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_unsignedhex_fd(unsigned long nbr, char *base, int fd);

void	ft_print_hex(unsigned int nbr, char c, int *count)
{
	if (c == 'x')
		ft_put_unsignedhex_fd(nbr, "0123456789abcdef", 1);
	else if (c == 'X')
		ft_put_unsignedhex_fd(nbr, "0123456789ABCDEF", 1);
	*count = *count + ft_num_digits_unsigned(nbr, 16);
}

void	ft_print_ptr(unsigned long ptr, int *count)
{
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		*count = *count + 5;
		return ;
	}
	ft_putstr_fd("0x", 1);
	ft_put_unsignedhex_fd(ptr, "0123456789abcdef", 1);
	*count = *count + ft_num_digits_unsigned(ptr, 16) + 2;
}

static void	ft_put_unsignedhex_fd(unsigned long nbr, char *base, int fd)
{
	if (nbr >= 16)
		ft_put_unsignedhex_fd(nbr / 16, base, fd);
	ft_putchar_fd(base[nbr % 16], fd);
}
