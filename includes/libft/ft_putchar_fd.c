/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 01:44:21 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/15 05:38:19 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

// @brief Outputs the character `c` to the specified file descriptor `fd`,
// using `write()`.
// @param c The character to output.
// @param fd The file descriptor on which to write.
// @return Number of bytes written.
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

// int main(void)
// {
// 	ft_putchar_fd('a', 1);
// 	return (0);
// }
