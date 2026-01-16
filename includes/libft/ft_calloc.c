/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 02:01:43 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:53:12 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// @brief Allocates memory for an array of `n` elements of `size` bytes each
// and returns a pointer to the allocated memory.
// The memory is set to zero.
// @param n Number of elements in the array.
// @param size Size in bytes of each element of the array.
// @return - If `n` or `size` is 0, then ft_calloc() returns a unique pointer
// value that can later be successfully passed to free().
// @return - If the multiplication of `n` and `size` would result in
// integer overflow, then ft_calloc() returns an error.
// @return - On error, returns `NULL`.
void	*ft_calloc(size_t n, size_t size)
{
	char	*ptr_array;
	size_t	i;

	ptr_array = malloc(n * size);
	if (ptr_array != NULL)
	{
		i = 0;
		while (i < (n * size))
		{
			ptr_array[i] = '\0';
			i++;
		}
	}
	return (ptr_array);
}
