/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 04:01:33 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:54:41 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Scans the `n` first bytes of the memory area pointed to by `s`
// for the first instance of the character `c`.
// @param s Memory area in which to look for `c`.
// @param c Character (`unsigned char`) to look for in `s`.
// @param n Number of bytes to scan in the memory area `s`.
// @return A pointer to the matching byte ;
// or `NULL` if the character does not occur in the given memory area.
// @note Both `c` and the bytes of the memory area pointed to by `s`
// are interpreted as `unsigned char`.
// @warning Will overflow if `n` is bigger than the memory area `s`.
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr_s;

	ptr_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr_s[i] == (unsigned char)c)
		{
			return ((void *)&ptr_s[i]);
		}
		i++;
	}
	return (NULL);
}
