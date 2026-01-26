/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_whitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:59:33 by ancourti          #+#    #+#             */
/*   Updated: 2026/01/26 13:00:43 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Check if a character is whitespace, as defined by the
/// ISO C Standard.
/// Whitespace characters include the following :
/// `' '`, `\t`, `\n` , `\v`, `\f` and `\r`.
/// @param c Character to check.
/// @return True (1) or False (0).
int	ft_is_whitespace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
	{
		return (1);
	}
	return (0);
}
