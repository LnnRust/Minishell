/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 00:53:37 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:55:47 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Locate the first occurence of a character in a string.
// The terminating null byte is considered to be part of the string.
// @param s Pointer to string.
// @param c Character to look for in `s`.
// @return A pointer to the first occurrence of the
// character `c` in the string `s`; or `NULL` if the character is not found.
// If `c = '\0'`, it returns a pointer to the terminator.
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
