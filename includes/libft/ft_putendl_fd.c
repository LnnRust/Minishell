/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 01:56:26 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:55:35 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

// @brief Outputs the string `s` to the specified file descriptor, followed
// by a newline (`\n`), using `write()`.
// @param c Pointer to the string to output.
// @param fd The file descriptor on which to write.
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	ft_putendl_fd("bonjour", 1);
// 	return (0);
// }
