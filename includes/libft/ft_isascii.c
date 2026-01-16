/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:02:23 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:53:21 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Check if a character is in the ASCII range.
// ASCII characters are coded on 7 bits, so they stop at 127 included.
// @param c Character to check.
// @return True (1) or False (0).
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

// int	main(void)
// {
// 	char	test;
// 	char	*ptr_test;

// 	ptr_test = &test;
// 	test = '0' + ft_isascii(' ');
// 	write(1, ptr_test, 1);
// 	return (0);
// }
