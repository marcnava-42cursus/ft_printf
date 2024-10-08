/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:57:48 by marcnava          #+#    #+#             */
/*   Updated: 2024/10/08 19:41:20 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define FT_MAYUS 0
# define FT_MINUS 1

int		ft_printf(char const *format, ...);
void	ft_str_types(char const *format, va_list args, size_t *size);
void	ft_decimal_types(char const *format, va_list args, size_t *size);
void	ft_hex_types(char const *format, va_list args, size_t *size);
void	ft_special_types(char const *format, va_list args, size_t *size);
void	ft_print_hex(unsigned int n, size_t *size, unsigned int capitalize);
void	ft_print_pointer(unsigned long long n, size_t *size);

void	ft_putnbr_printf(int n, size_t *size);
void	ft_putunbr_printf(unsigned int n, size_t *size);

#endif