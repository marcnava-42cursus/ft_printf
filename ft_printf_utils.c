/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:25:52 by marcnava          #+#    #+#             */
/*   Updated: 2024/10/08 16:36:37 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_str_types(char const *format, va_list args)
{
	if (*format == 'c')
		ft_putchar_fd(va_arg(args, int), STDOUT_FILENO);
	else if (*format == 's')
		ft_putstr_fd(va_arg(args, char *), STDOUT_FILENO);
}

void	ft_decimal_types(char const *format, va_list args)
{
	if (*format == 'd')
		ft_putnbr_fd(va_arg(args, int), STDOUT_FILENO);
	else if (*format == 'i')
		ft_putnbr_fd(va_arg(args, int), STDOUT_FILENO);
	else if (*format == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), STDOUT_FILENO);
}

void	ft_hex_types(char const *format, va_list args)
{
	if (*format == 'x')
		ft_print_hex(va_arg(args, unsigned int), FT_MINUS);
	else if (*format == 'X')
		ft_print_hex(va_arg(args, unsigned int), FT_MAYUS);
}

void	ft_spetial_types(char const *format, va_list args)
{
	if (*format == '%')
		ft_putchar_fd('%', STDOUT_FILENO);
	else if (*format == 'p')
		ft_print_pointer(va_arg(args, unsigned long long));
}
