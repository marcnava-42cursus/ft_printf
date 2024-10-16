/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:33:17 by marcnava          #+#    #+#             */
/*   Updated: 2024/10/16 18:57:58 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdbool.h>

typedef struct s_flags
{
	// #
	bool	adapter;
	// - 0
	char	minuszero;
	// + \32
	char	plusspace;
	// Longitud
	int		lenght;
	// .
	int		precision;
	// Letra
	char	modifier;
	// Si falla algo
	bool	error;
}	t_flags;

int	ft_printf_bonus(char const *format);

#endif