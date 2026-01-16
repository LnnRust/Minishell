/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 00:01:51 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 20:38:36 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Copies `n` bytes from memory area `src` to memory area `dest`.
// The memory areas may overlap :
// copying takes place as though the bytes in `src` are first copied
// into a temporary array that does not overlap `src`
// or `dest`, and the bytes are then copied from the temporary array to `dest`.
// If an overlap is detected, memove will copy from the end.
// @param *dest Destination pointer.
// @param *src Source pointer.
// @param n Bytes to copy.
// @return Destination address
// @warning `ft_memmove()` is more PROTECTED than the original `memmove()` :
// @warning - Does not segfault when `NULL` params are sent,
// returns `NULL` in that case.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*ptr_src;
	char		*ptr_dest;
	int			i;

	if (src == NULL && dest == NULL)
	{
		return (ft_memcpy(dest, (void *)src, n));
	}
	if (n == 0)
	{
		return (dest);
	}
	ptr_src = src;
	ptr_dest = dest;
	if (ptr_dest > ptr_src)
	{
		i = n - 1;
		while (i >= 0)
		{
			ptr_dest[i] = ptr_src[i];
			i--;
		}
		return (dest);
	}
	return (ft_memcpy(dest, (void *)src, n));
}
// #include <string.h>
// int	main(void)
// {
// 	char	array_0[8] = "Bonjour";
// 	char	array_1[10] = "konichiwa";

// 	void	*ptr_array0 = &array_0[0];
// 	void	*ptr_array1 = &array_0[4];

// 	printf("%s %s\n", "Source (initial) :", array_0);
// 	printf("%s %s\n", "Destination (initial) :", array_1);

// 	ft_memmove(ptr_array1, ptr_array0, 3);

// 	printf("%s %s\n", "Source (after) :", array_0);
// 	printf("%s %s\n", "Destination (after) :", array_1);

// 	return (0);
// }
