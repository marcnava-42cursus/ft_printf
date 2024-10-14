/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:15:53 by marcnava          #+#    #+#             */
/*   Updated: 2024/09/29 16:06:05 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
}

// int	main(void)
// {
// 	char	*str = "lojlololololohololololololo";
// 	char	*set = "lo";
// 	char	*trimmed = ft_strtrim(str, set);
// 	printf("Original: \"%s\"\n", str);
// 	printf("Trimmed: \"%s\"\n", trimmed);
// 	free(trimmed);
// 	return (0);
// }
