/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 01:59:10 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:58:24 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Appends the NUL-terminated string `src` to the end of `dst`.
// It will append at most `size - strlen(dst) - 1` bytes,
// NUL-terminating the result,
// (as long as there is at least one byte free in dst).
// A byte for the `NUL` should be included in `size`.
// @warning If `ft_strlcat()` traverses size characters without finding a `NUL`,
// the length  of the string is considered to be `size`
// and the destination string WILL NOT be NUL-terminated
// (since there was no space for the NUL).
// This keeps `ft_strlcat()` from running off the end of a string.
// In practice this should not happen (as it means that either size is
// incorrect or that dst is not a proper “C” string).
// The check exists to prevent potential security problems in incorrect code.
// @return Total length of the string they tried to create.
// For `ft_strlcat()` that means the initial length of `dst`
// plus the length of `src`.
// @param dst Destination pointer.
// @param src Source pointer.
// @param dstsize Size of the destination in Bytes.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const char	*odst = dst;
	const char	*osrc = src;
	size_t		n;
	size_t		dlen;

	n = dstsize;
	while (n-- != 0 && *dst != '\0')
	{
		dst++;
	}
	dlen = dst - odst;
	n = dstsize - dlen;
	if (n-- == 0)
		return (dlen + ft_strlen(src));
	while (*src != '\0')
	{
		if (n != 0)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - osrc));
}
