/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 00:56:25 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:59:24 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Get uppercase of character if it exists.
// @return Uppercase version of character if it exists,
// or original character if it does not exist.
int	ft_toupper(int character)
{
	if (character >= 'a' && character <= 'z')
	{
		character = character - 32;
	}
	return (character);
}

// int	main(void)
// {
// 	printf("%c\n", toupper('A'));

// 	return (0);
// }
