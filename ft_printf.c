/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:55:54 by marcnava          #+#    #+#             */
/*   Updated: 2024/10/08 16:55:09 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c' || *format == 's')
				ft_str_types(format, args);
			else if (*format == 'd' || *format == 'i' || *format == 'u')
				ft_decimal_types(format, args);
			else if (*format == 'x' || *format == 'X')
				ft_hex_types(format, args);
			else if (*format == '%' || *format == 'p')
				ft_spetial_types(format, args);
		}
		else
			ft_putchar_fd(*format, STDOUT_FILENO);
		format++;
	}
	va_end(args);
	return (0);
}
