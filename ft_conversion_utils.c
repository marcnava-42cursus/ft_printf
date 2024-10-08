/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:17:31 by marcnava          #+#    #+#             */
/*   Updated: 2024/10/08 16:36:58 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_print_hex(unsigned int n, unsigned int capitalize)
{
	if (n >= 16)
		ft_print_hex((n / 16), capitalize);
	if (n % 16 < 10)
		ft_putchar_fd(n % 16 + '0', STDOUT_FILENO);
	else
	{
		if (capitalize)
			ft_putchar_fd(n % 16 - 10 + 'a', STDOUT_FILENO);
		else
			ft_putchar_fd(n % 16 - 10 + 'A', STDOUT_FILENO);
	}
}

void	ft_print_pointer(unsigned long long n)
{
	if (n == 0)
		ft_putstr_fd("0x0", STDOUT_FILENO);
	else
	{
		ft_putstr_fd("0x", STDOUT_FILENO);
		ft_print_hex(n, FT_MINUS);
	}
}
