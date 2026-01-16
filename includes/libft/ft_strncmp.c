/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 01:15:58 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 18:34:14 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Compares the first (at most) `n` bytes of
// the two strings `s1` and `s2`.
// This function starts by comparing the first character of each string.
// While they are equal to each other, it continues until the characters differ,
// until a terminating null-character is reached,
// or until num characters match in both strings, whichever happens first.
// @param s1 First string.
// @param s2 Second string.
// @param n Number of characters to compare (at most).
// @return (0, if the `s1` and `s2` are equal);
// a negative value if `s1` is less than `s2`;
// a positive value if `s1` is greater than `s2`.
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
	{
		return (0);
	}
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <string.h>

// int	main(void)
// {
// 	printf("%s%i\n", "ft_strncmp() : ", ft_strncmp("abcdefgh", "abcdwxyz", 4));
// 	printf("%s%i\n", "strncmp() : ", strncmp("abcdefgh", "abcdwxyz", 4));
// 	return (0);
// }
