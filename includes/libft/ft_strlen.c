/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:02:31 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:58:51 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Calculates the length of the string pointed to by s,
// excluding the terminating null byte ('\0').
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	printf ("%s %i\n", "ft_strlen :", (int) ft_strlen("bonjour"));
// 	return (0);
// }
