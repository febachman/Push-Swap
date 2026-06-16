/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:18:13 by fbachman          #+#    #+#             */
/*   Updated: 2026/06/03 09:34:44 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*INCLUDES*/

# include <stdarg.h>
# include "libft/libft.h"

/*PROTOTYPES*/

//main function
int		ft_printf(const char *format, ...);

//dispatcher function
void	ft_dispatcher(char c, va_list tokens, int *count);

//printers functions
void	ft_print_char(char c, int *count);
void	ft_print_str(char *str, int *count);
void	ft_print_decimal(int nbr, int *count);
void	ft_print_unsigned(unsigned int nbr, int *count);
void	ft_print_hex(unsigned int nbr, char c, int *count);
void	ft_print_ptr(unsigned long ptr, int *count);

//utility functions
int		ft_num_digits_signed(long nbr, int base);
int		ft_num_digits_unsigned(unsigned long nbr, int base);

#endif