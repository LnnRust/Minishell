/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 22:31:41 by ancourti          #+#    #+#             */
/*   Updated: 2026/01/16 03:52:14 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

// @brief Write an int number (base 16) to the file descriptor `fd`
// using a recursive function and modulo. Writes in BIG CAPS.
//
// Principle :
//
// - Modulo (`%`) of a number gives you the last digit (0 to F).
//
// - Dividing (`/`) by base (16) "removes" the last digit.
//
// - This way, you can recover each digit of the number successfully.
// @return Number of bytes written.
int	ft_puthexa_fd(unsigned int n, int fd)
{
	if (n < 16)
	{
		if (n < 10)
			n = n + '0';
		else
			n = n + 'a' - 10;
		return (write(fd, &n, 1));
	}
	else
	{
		ft_puthexa_fd(n / 16, fd);
		ft_puthexa_fd(n % 16, fd);
		return (ft_count_digits(n, 16));
	}
}

// @brief Write an int number (base 16) to the file descriptor `fd`
// using a recursive function and modulo. Writes in small caps.
//
// Principle :
//
// - Modulo (`%`) of a number gives you the last digit (0 to F).
//
// - Dividing (`/`) by base (16) "removes" the last digit.
//
// - This way, you can recover each digit of the number successfully.
// @return Number of bytes written.
int	ft_puthexa_caps_fd(unsigned int n, int fd)
{
	if (n < 16)
	{
		if (n < 10)
			n = n + '0';
		else
			n = n + 'A' - 10;
		return (write(fd, &n, 1));
	}
	else
	{
		ft_puthexa_caps_fd(n / 16, fd);
		ft_puthexa_caps_fd(n % 16, fd);
		return (ft_count_digits(n, 16));
	}
}

// @brief Write the unsigned long `n` to the specified file descriptor `fd`,
// using `write()`, as a hexadecimal number.
// @param n Number to write in hex.
// @param fd File decriptor.
// @return Number of bytes written.
static int	ft_puthexa_long_fd(unsigned long n, int fd)
{
	if (n < 16)
	{
		if (n < 10)
			n = n + '0';
		else
			n = n + 'a' - 10;
		return (write(fd, &n, 1));
	}
	else
	{
		ft_puthexa_long_fd(n / 16, fd);
		ft_puthexa_long_fd(n % 16, fd);
		return (ft_count_digits(n, 16));
	}
}

// @brief Write the adress of a pointer `p` to the specified
// file descriptor `fd`, using `write()`, as a hexadecimal number
// preceded by `0x`.
//
// Example : `0x55db0355c010`.
// The adress of the pointer is interpreted as `unsigned long`.
// @param p Pointer address to write in hex.
// @param fd File decriptor.
// @return Number of bytes written.
int	ft_putpointer(void *p, int fd)
{
	if (p == NULL)
	{
		return (write(fd, "(nil)", 5));
	}
	return (ft_putstr_fd("0x", fd) + ft_puthexa_long_fd((unsigned long)p, fd));
}


