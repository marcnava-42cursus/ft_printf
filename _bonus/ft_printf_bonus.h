/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:33:17 by marcnava          #+#    #+#             */
/*   Updated: 2024/10/22 21:36:18 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../libft/libft.h"

/**
 * adapter		-> #
 * minuszero	-> - / 0
 * plusspace	-> + / ' '
 * lenght		-> lenght of the flag
 * precission	-> .
 * modifier		-> type of data
 * error		-> if something fails
 */
typedef struct s_flags
{
	int		adapter;
	char	minuszero;
	char	plusspace;
	int		length;
	int		precision;
	char	modifier;
	int		error;
}	t_flags;

int		ft_printf(char const *format, ...);
int		analyze_pattern(const char *format, va_list args, int *size);
void	print_flags(const t_flags *flags);
int		is_flag(char c);
void	init_flags(t_flags *flags);

t_flags	parse_format(const char *str);
int		parse_flags(const char **ptr, t_flags *flags);
int		parse_length(const char **ptr, t_flags *flags);
int		parse_precision(const char **ptr, t_flags *flags);
int		parse_modifier(const char **ptr, t_flags *flags);

#endif