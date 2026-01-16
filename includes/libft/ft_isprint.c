/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:02:29 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:53:02 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Check if a character is ASCII printable.
// Printable ASCII characters go from 'SPACE' (32) to '~' (126).
// @param c Character to check.
// @return True (1) or False (0).
int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
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
// 	test = '0' + ft_isprint('d');
// 	write(1, ptr_test, 1);
// 	return (0);
// }
