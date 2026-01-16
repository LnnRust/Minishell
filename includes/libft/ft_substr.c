/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 02:57:56 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 13:01:16 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Allocates memory using `malloc()` and returns a substring from the
// string `s`. The substring starts at index `start` and has a maximum
// length of `len`.
// @param s The original string from which to create the substring.
// @param start The starting index of the substring within `s`.
// @param len The maximum length of the substring.
// @return (The substring); or `NULL` if the allocation fails.
char	*ft_substr(char const *s, unsigned int start_pos, size_t len)
{
	char	*substring;
	size_t	i;

	if (start_pos >= ft_strlen(s) || s[0] == '\0')
	{
		substring = malloc(sizeof(char) * 1);
		if (substring == NULL)
			return (NULL);
		substring[0] = '\0';
		return (substring);
	}
	if (ft_strlen(s) - start_pos < len)
		len = ft_strlen(s) - start_pos;
	substring = malloc(sizeof(char) * (len + 1));
	if (substring == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start_pos + i] != '\0')
	{
		substring[i] = s[start_pos + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
// int	main(void)
// {
// 	ft_substr("", 0, 0);
// 	return (0);
// }
