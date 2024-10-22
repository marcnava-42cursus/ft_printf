/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:55:54 by marcnava          #+#    #+#             */
/*   Updated: 2024/10/22 22:10:29 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_choose_types(const char *format, va_list args,
	t_flags flags, int *size)
{
	args = 0;
	size = 0;
	char a = *format;
	a = 0;
	ft_putstr_fd(&flags.modifier, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	// if (flags.modifier == 'c' || flags.modifier == 's')
	// 	ft_str_types(flags, args, size);
	// else if (flags.modifier == 'd' || flags.modifier == 'i'
	// 	|| flags.modifier == 'u')
	// 	ft_decimal_types(flags, args, size);
	// else if (flags.modifier == 'x' || flags.modifier == 'X')
	// 	ft_hex_types(flags, args, size);
	// else if (flags.modifier == '%' || flags.modifier == 'p')
	// 	ft_special_types(flags, args, size);
	// else if (flags.modifier == '\0')
	// {
	// 	(*size) = -1;
	// 	return ;
	// }
	// else
	// {
	// 	ft_putchar_fd('%', STDOUT_FILENO);
	// 	ft_putchar_fd(flags.modifier, STDOUT_FILENO);
	// 	(*size) += 2;
	// }
}

int	analyze_pattern(const char *format, va_list args, int *size)
{
	const char	*ptr = format;
	t_flags		flags;

	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			flags = parse_format(ptr);
			if (flags.error)
				return (0);
			ptr++;
			ft_choose_types(format, args, flags, size);
			while (*ptr && *ptr != ' ' && !ft_isalpha(*ptr))
				ptr++;
			if (*ptr)
				ptr++;
		}
		else
		{
			ptr++;
		}
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;

	va_start(args, format);
	size = 0;
	if (!analyze_pattern(format, args, &size))
	{
		va_end(args);
		return (-1);
	}
	va_end(args);
	return (size);
}
