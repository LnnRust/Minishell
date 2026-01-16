/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 00:53:37 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:59:03 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Locate last occurence of a character in a string.
// The terminating null byte is considered part of the string.
// @param s String in which to look the character.
// @param c Character to look for in string s.
// @return A pointer to the first occurrence of the
// character `c` in the string `s`; or `NULL` if the character is not found.
// If `c = '\0'`, it returns a pointer to the terminator.
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if ((char)s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (NULL);
}
