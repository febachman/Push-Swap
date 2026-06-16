/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:38:38 by fbachman          #+#    #+#             */
/*   Updated: 2026/05/26 11:42:46 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_digits(long nbr)
{
	int		dig;

	dig = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		dig++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		dig++;
	}
	return (dig);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;

	nbr = n;
	len = num_digits(nbr);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		len--;
		str[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}
