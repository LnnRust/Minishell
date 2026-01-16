/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:50:48 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:52:34 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief ASCII to integer. Convert a string to an integer, base 10 (ten).
// The string may begin with an arbitrary amount of white space as defined
// by `isspace()`
// followed by a single optional '+' or '-' sign.
// The function reads the string until a non-conforming character
// is encountered and returns the number obtained so far.
// @return The converted value (int) or `0` on error.
// @param str Pointer to the string in which to find a number
// @warning `ft_atoi()` does not detect errors. No checks for overflow
// or underflow are done. Only base-10 (ten) input can be converted.
int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	sign = 1;
	n = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (sign * n);
}
