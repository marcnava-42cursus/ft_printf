/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:55:54 by marcnava          #+#    #+#             */
/*   Updated: 2024/10/08 19:41:41 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_choose_types(char const *format, va_list args, size_t *size)
{
	if (*format == 'c' || *format == 's')
		ft_str_types(format, args, size);
	else if (*format == 'd' || *format == 'i' || *format == 'u')
		ft_decimal_types(format, args, size);
	else if (*format == 'x' || *format == 'X')
		ft_hex_types(format, args, size);
	else if (*format == '%' || *format == 'p')
		ft_special_types(format, args, size);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	size_t	size;

	va_start(args, format);
	size = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_choose_types(format, args, &size);
		}
		else
		{
			ft_putchar_fd(*format, STDOUT_FILENO);
			size++;
		}
		format++;
	}
	va_end(args);
	return (size);
}
