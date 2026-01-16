/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlmapi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:19:27 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:58:53 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Applies the function `f()` to each character of the string `s`.
//
// `ft_strmapi()` passes to the function `f()` as arguments the following :
// @brief - Index as the first argument.
// @brief - The character itself as the second.
//
// A new string is created using `malloc()` to store the results
// from the successive applications of `f()`.
// @param s Pointer to the string to iterate over.
// @param f Pointer to the function to apply to each character.
// @return - The string created from the successive applications of `f`.
// @return - `NULL` if the allocation fails.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*buffer;

	buffer = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (buffer == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0')
	{
		buffer[i] = f(i, s[i]);
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

// char f (unsigned int i, char c)
// {
// 	return (c + i);
// }

// int main(void)
// {
// 	printf("%s", ft_strmapi("bonjour", f));
// 	return (0);
// }
