/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:55:54 by marcnava          #+#    #+#             */
/*   Updated: 2024/10/16 18:56:42 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../libft/libft.h"
#include <stdio.h>

static t_flags	*ft_check_flags(char const *format)
{
	char	*str;
	char	*tmp;
	t_flags	*flags;

	flags = ft_calloc(1, sizeof(t_flags));
	tmp = ft_strdup(format);
	str = tmp;
	if (!flags || !str)
		return (NULL);
	while (!ft_isdigit(*str) && *str != '0' && *str != '\0')
	{
		if (*str == '#')
			flags->adapter = true;
		else if (*str == '-')
			flags->minuszero = '-';
		else if (*str == '0' && flags->minuszero != '-')
			flags->minuszero = '0';
		else if (*str == '+')
			flags->plusspace = '+';
		else if (*str == ' ' && flags->plusspace != '+')
			flags->plusspace = ' ';
		str++;
	}
	free(tmp);
	return (flags);
}

int	ft_printf_bonus(char const *format)
{
	t_flags	*flags;

	flags = ft_check_flags(format);

	printf("%d : %d : %d", flags->adapter, flags->minuszero, flags->plusspace);
	return (0);
}
