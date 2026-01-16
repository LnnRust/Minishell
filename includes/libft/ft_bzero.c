/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:17:36 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:53:13 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Fills the first `n` bytes of the memory area
// pointed to by `s`, with zeroes (`\0`).
// @param s String to fill.
// @param n Number of bytes to fill in `s`.
// @return Pointer to the memory area `s`.
// @warning Will overflow if `n` is bigger than the memory area `s`.
void	*ft_bzero(void *s, size_t n)
{
	char	*buffer;
	int		i;

	buffer = s;
	i = 0;
	while (i < (int)n)
	{
		buffer[i] = '\0';
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	// char	bonjour[16] = "konichiwa";
// 	// char	*ptr_bonjour = &bonjour;

// 	char	array[4] = "abc";
// 	char 	*ptr_array = &array[0];

// 	printf("%s%i %i %i\n", "Array d'origine : ", array[0], array[1], array[2]);

// 	ft_bzero(ptr_array, 3);
// 	printf("%s%c %c %c\n", "Après ft_memset (char): ", array[0], array[1],
//		array[2]);
// 	printf("%s%i %i %i\n", "Après ft_memset (int, dec): ", array[0], array[1],
//		array[2]);
// 	printf("%s%x %x %x\n", "Après ft_memset (int, hex): ", array[0], array[1],
//		array[2]);

// 	return (0);
// }
