/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 01:36:29 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:55:52 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Applies the function `f()` to each character of the string `s`.
//
// `ft_striteri()` passes to the function `f()` as arguments the following :
// @brief - Index as the first argument.
// @brief - The character itself as the second.
//
// Each character is passed by address to `f()` so it can be
// modified if necessary.
// @param s Pointer to the string to iterate over.
// @param f Pointer to the function to apply to each character.
// @return The string created from the successive applications of `f`.
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
