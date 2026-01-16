/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 02:00:55 by ancourti          #+#    #+#             */
/*   Updated: 2026/01/16 03:51:15 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Outputs the integer `n` to the specified file descriptor
// using `write()`.
// @param n The integer to output.
// @param fd The file descriptor on which to write.
// @return Number of bytes written.
int	ft_putnbr_fd(int n, int fd)
{
	int	is_negative;

	is_negative = 0;
	if (n == -2147483648)
	{
		return (write(fd, "-2147483648", 11));
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		is_negative = 1;
		n = n * -1;
	}
	if (n >= 0 && n < 10)
	{
		n = n + '0';
		return (write(fd, &n, 1) + is_negative);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
		return (ft_count_digits(n, 10) + is_negative);
	}
}

// @brief Write the unsigned integer `n` to the specified
// file descriptor `fd` using `write()`.
// Will not print any sign. Can overflow ?
// @param n The unsigned integer to output.
// @param fd The file descriptor on which to write.
// @return Number of bytes written.
int	ft_putnbr_u_fd(unsigned int n, int fd)
{
	if (n < 10)
	{
		n = n + '0';
		return (write(fd, &n, 1));
	}
	else
	{
		ft_putnbr_u_fd(n / 10, fd);
		ft_putnbr_u_fd(n % 10, fd);
		return (ft_count_digits(n, 10));
	}
}
// @brief Counts the number of digits in a number, given its base.
// Examples :
//
// - Ten (10) decimal (base 10) will return two (2).
//
// - Ten (A) hexadecimal (base 16) will return one (1).
// @param n Number to process.
// @param base Base, for example 10 (decimal) or 16 (hexadecimal).
// @return Number of digits, in base 10 (decimal).
int	ft_count_digits(unsigned long n, int base)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}
