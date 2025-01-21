/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:54:22 by marcnava          #+#    #+#             */
/*   Updated: 2024/11/19 19:17:10 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static char	*ft_ltoa_base_conversion(long n, const char *base, size_t digits)
{
	char	*num_str;

	num_str = (char *)ft_calloc(digits + 1, sizeof(char));
	if (!num_str)
		return (NULL);
	while (digits-- > 0)
	{
		num_str[digits] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	return (num_str);
}

char	*ft_ltoa_base(long n, const char *base)
{
	const size_t	base_len = ft_strlen(base);
	size_t			digits;
	int				neg;
	char			*num_str;

	if (n == 0)
		return (ft_strdup("0"));
	neg = 0;
	if (n < 0)
	{
		if (n == LONG_MIN)
			return (ft_strdup("-9223372036854775808"));
		neg = 1;
		n = -n;
	}
	digits = ft_count_digits(n, base_len);
	if (neg)
		digits++;
	num_str = ft_ltoa_base_conversion(n, base, digits);
	if (!num_str)
		return (NULL);
	if (neg)
		num_str[0] = '-';
	return (num_str);
}

char	*ft_ltoa_o(long n)
{
	return (ft_ltoa_base(n, "01234567"));
}

char	*ft_ltoa_x(long n)
{
	return (ft_ltoa_base(n, "0123456789abcdef"));
}

char	*ft_ltoa(long n)
{
	return (ft_ltoa_base(n, "0123456789"));
}
