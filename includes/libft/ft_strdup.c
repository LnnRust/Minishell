/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 02:42:30 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:55:49 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Duplicate a string.
// @param s Source string to duplicate.
// @return - On success, a pointer to a new string which is a
// duplicate of the string `s`.
// @return - If insufficient memory was available, `NULL`.
char	*ft_strdup(const char *s)
{
	char	*ptr_duplicate;
	int		i;

	i = 0;
	ptr_duplicate = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ptr_duplicate != NULL)
	{
		while (s[i] != '\0')
		{
			ptr_duplicate[i] = s[i];
			i++;
		}
		ptr_duplicate[i] = '\0';
	}
	return (ptr_duplicate);
}
