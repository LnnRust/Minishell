/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 01:47:32 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:55:55 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Allocates memory using `malloc()` and returns a
// new string, which is the result of concatenating
// `s1` and `s2`.
// @param s1 The prefix string.
// @param s2 The suffix string.
// @return (The new string); or `NULL` if the allocation fails.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	int		i;
	int		j;

	joined_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (joined_str == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		joined_str[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i] != '\0')
	{
		joined_str[j] = s2[i];
		i++;
		j++;
	}
	joined_str[j] = '\0';
	return (joined_str);
}
