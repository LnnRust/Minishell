/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 00:46:17 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:58:48 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Copies up to (size - 1) characters from
// the NUL-terminated string `src` to `dst`, NUL-terminating the result.
// @return Total length of the string `ft_strlcpy()` tried to create,
// i.e., the length of `src`.
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_lenght;

	src_lenght = ft_strlen(src);
	if (src_lenght >= size)
	{
		if (size > 0)
		{
			ft_memcpy((void *)dst, (void *)src, size);
			dst[size - 1] = '\0';
		}
	}
	else
	{
		ft_memcpy((void *)dst, (void *)src, src_lenght + 1);
	}
	return (src_lenght);
}
