/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 22:55:41 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 22:18:02 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

// @brief Copy `n` bytes from the memory area `src` to memory area `dest`.
// @param dest Pointer to destination memory area.
// @param src Pointer to source memory area
// @param numBytes Number of bytes to copy from `src` to `dest`.
// @note The memory areas must not overlap.
// @return Destination address
// Use `ft_memmove()` if the memory areas do overlap.
void	*ft_memcpy(void *dest, const void *src, size_t numBytes)
{
	int	i;

	if (src == NULL && dest == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < (int)numBytes)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	array_0[8] = "Bonjour";
// 	char	array_1[10] = "konichiwa";

// 	void	*ptr_array0 = "wazaaa";
// 	void	*ptr_array1 = NULL;

// 	printf("%s %s\n", "Source (initial) :", array_0);
// 	printf("%s %s\n", "Destination (initial) :", array_1);

// 	memcpy(ptr_array1, ptr_array0, 4);

// 	printf("%s %s\n", "Destination (after) :", array_1);

// 	return (0);
// }
