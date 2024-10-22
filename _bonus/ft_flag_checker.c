/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:47:24 by marcnava          #+#    #+#             */
/*   Updated: 2024/10/22 21:36:51 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_flags	parse_format(const char *str)
{
	t_flags		flags;
	const char	*ptr = str;

	init_flags(&flags);
	if (*ptr != '%')
	{
		flags.error = 1;
		return (flags);
	}
	ptr++;
	if (!parse_flags(&ptr, &flags)
		|| !parse_length(&ptr, &flags)
		|| !parse_precision(&ptr, &flags)
		|| !parse_modifier(&ptr, &flags))
		flags.error = 1;
	return (flags);
}

void	print_flags(const t_flags *flags)
{
	printf("\tAdapter (#): %d\n", flags->adapter);
	printf("\tMinusZero (-/0): %c\n", flags->minuszero);
	printf("\tPlusSpace (+/space): %c\n", flags->plusspace);
	printf("\tLength: %d\n", flags->length);
	printf("\tPrecision: %d\n", flags->precision);
	printf("\tModifier: %c\n", flags->modifier);
	printf("\tError: %d\n", flags->error);
}

int	is_flag(char c)
{
	return (ft_strchr("#+-0 ", c) != NULL);
}

void	init_flags(t_flags *flags)
{
	flags->adapter = 0;
	flags->minuszero = '\0';
	flags->plusspace = '\0';
	flags->length = 0;
	flags->precision = -1;
	flags->modifier = '\0';
	flags->error = 0;
}
