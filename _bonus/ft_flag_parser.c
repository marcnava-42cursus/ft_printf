/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:07:26 by marcnava          #+#    #+#             */
/*   Updated: 2024/10/22 21:02:57 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	parse_flags(const char **ptr, t_flags *flags)
{
	while (is_flag(**ptr))
	{
		if (**ptr == '#')
			flags->adapter = 1;
		else if (**ptr == '-')
			flags->minuszero = '-';
		else if (**ptr == '0' && flags->minuszero != '-')
			flags->minuszero = '0';
		else if (**ptr == '+')
			flags->plusspace = '+';
		else if (**ptr == ' ' && flags->plusspace != '+')
			flags->plusspace = ' ';
		(*ptr)++;
	}
	return (!is_flag(**ptr));
}

int	parse_length(const char **ptr, t_flags *flags)
{
	flags->length = 0;
	while (ft_isdigit(**ptr))
	{
		flags->length = flags->length * 10 + (**ptr - '0');
		(*ptr)++;
	}
	return (1);
}

int	parse_precision(const char **ptr, t_flags *flags)
{
	if (**ptr == '.')
	{
		(*ptr)++;
		flags->precision = 0;
		while (ft_isdigit(**ptr))
		{
			flags->precision = flags->precision * 10 + (**ptr - '0');
			(*ptr)++;
		}
	}
	else
		flags->precision = -1;
	return (1);
}

int	parse_modifier(const char **ptr, t_flags *flags)
{
	if (ft_isalpha(**ptr))
	{
		flags->modifier = **ptr;
		(*ptr)++;
		return (1);
	}
	return (0);
}
