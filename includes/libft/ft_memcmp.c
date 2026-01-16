/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 04:18:10 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:54:44 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Compares the first `n` bytes (each interpreted as `unsigned char`)
// of the memory areas `s1` and `s2`.
// @param s1 Pointer to string 1.
// @param s2 Pointer to string 2.
// @param n Number of bytes to compare.
// @return Difference of the first different character between the
// two memory areas (`s1` - `s2`). Zero (0) if `s1` = `s2`.
// @warning Will overflow if `n` is bigger than the memory area `s`.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	if (n == 0)
	{
		return (0);
	}
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr_s1[i] != ptr_s2[i])
		{
			return ((unsigned char)ptr_s1[i] - (unsigned char)ptr_s2[i]);
		}
		i++;
	}
	return (0);
}
// int main(void)
// {
//     int res = 0;
//     char s1[10] = "";
//     char s2[10] = "";

//     // Use memcmp() to compare s1 and s2 up to
//   	// length of s1
//     res = ft_memcmp(s1, s2, ft_strlen(s1));

//     // Check the result of memcmp
//     if (res > 0)
//         printf("s1 is greater");
//     else if (res < 0)
//         printf("s2 is greater");
//     else
//         printf("both are equal");

//     return (0);
// }
