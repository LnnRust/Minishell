/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 01:52:42 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/16 19:20:11 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

// @brief Write the string `s` to the specified file descriptor `fd`, using
// `write()`.
// @param s Pointer to the string to output.
// @return Number of bytes written.
int	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
	{
		return (write(fd, "(null)", 6));
	}
	return (write(fd, s, ft_strlen(s)));
}

// int main(void)
// {
// 	ft_putstr_fd("bonjour", 1);
// 	return (0);
// }
