/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:24:14 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:53:24 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static char	*ft_rev_tab(char *src_array)
{
	int		len;
	char	*reversed_array;
	int		i;

	len = ft_strlen(src_array);
	reversed_array = malloc(sizeof(char) * (len + 1));
	if (reversed_array == NULL)
	{
		return (NULL);
	}
	i = 0;
	len = len - 1;
	while (len >= 0)
	{
		reversed_array[i] = src_array[len];
		i++;
		len--;
	}
	reversed_array[i] = '\0';
	return (reversed_array);
}

// @brief Int to ASCII. Allocates memory using `malloc()` and returns
// a string representing the integer received as an argument.
// Negative numbers must be handled.
// @param n The integer to convert.
// @return The string representing the integer.
// Or `NULL` if the allocation fails
char	*ft_itoa(int n)
{
	int		sign;
	int		i;
	char	buffer[12];

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	i = 0;
	while (n > 9)
	{
		buffer[i++] = n % 10 + '0';
		n = n / 10;
	}
	buffer[i++] = (n % 10) * (1 - 2 * (n < 0)) + '0';
	if (sign == -1)
	{
		buffer[i++] = '-';
	}
	buffer[i] = '\0';
	return (ft_rev_tab(buffer));
}

// #include <limits.h>
// int main(void)
// {
// 	printf("%s%s\n", "Result : ", ft_itoa(INT_MIN));
// 	return (0);
// }
