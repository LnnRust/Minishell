/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 01:09:34 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:59:19 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Get lowercase of character if it exists.
// @return Lowercase version of character if it exists,
// or original character if it does not exist.
int	ft_tolower(int character)
{
	if (character >= 'A' && character <= 'Z')
	{
		character = character + 32;
	}
	return (character);
}

// int	main(void)
// {
// 	printf("%c\n", ft_tolower('a'));

// 	return (0);
// }
