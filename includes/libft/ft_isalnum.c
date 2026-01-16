/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:22:27 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:53:16 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Check if a character is ASCII alphanumeric.
// @param c Character to check.
// @return True (1) or False (0).
int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
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
// 	test = '0' + ft_isalnum('b');
// 	write(1, ptr_test, 1);
// 	return (0);
// }
