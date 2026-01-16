/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:17:36 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:55:30 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Fills the first `n` bytes of the memory area
// pointed to by `s` with the constant byte `c`.
// @param s Pointer to the memory area to fill.
// @param c Character to fill memory with.
// @param n Number of bytes to fill in `s` with character `c`.
// @return Pointer to the memory area `s`.
// @warning Will overflow if `n` is bigger than the memory area `s`.
void	*ft_memset(void *s, int c, size_t n)
{
	char	*buffer;
	int		i;

	buffer = s;
	i = 0;
	while (i < (int)n)
	{
		buffer[i] = c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	// char	bonjour[16] = "konichiwa";
// 	// char	*ptr_bonjour = &bonjour;

// 	int	array[3] = {0};
// 	int 	*ptr_array = &array[0];

// 	printf("%s%i %i %i\n", "Array d'origine : ", array[0], array[1], array[2]);

// 	ft_memset (ptr_array, 42, 3);
// 	printf("%s%c %c %c\n", "Après (char): ", array[0], array[1], array[2]);
// 	printf("%s%i %i %i\n", "(int, dec): ", array[0], array[1], array[2]);
// 	printf("%s%x %x %x\n", "(int, hex): ", array[0], array[1], array[2]);

// 	return (0);
// }
