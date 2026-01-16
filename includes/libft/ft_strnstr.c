/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 04:48:55 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 13:06:54 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

// @brief Locate the first occurrence of the null-terminated string `little`
// in the string `big`, where not more than `len` characters are searched.
// @note Characters that appear after a `\0` character in either
// `big` or `little` are not searched.
// @param big String to search.
// @param little Pattern to look for in `big`.
// @param len Number of characters of `big` to search.
// @return - If `little` is found in `big`, then a pointer to the
// first character of the first occurrence of `little` in `big`
// is returned.
// @return - If `little` is an empty string, then `big` is returned
// @return - If `little` occurs nowhere in `big`, then `NULL` is returned.
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (little[0] == *"")
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (little[j] == big[i])
		{
			while (big[i] == little[j] && big[i] && little[j])
			{
				if (i++ == len)
					return (NULL);
				j++;
			}
			if (little[j] == '\0')
				return ((char *)&big[i - j]);
			i = (i - j);
		}
		i++;
		j = 0;
	}
	return (NULL);
}

// int main()
// {
//     char    *s1 = "MZIRIBMZIRIBMZE123";
//     char    *s2 = "MZIRIBMZE";
//     size_t  max = strlen(s2);
//     char    *i1 = strnstr(s1, s2, max);
//     char    *i2 = ft_strnstr(s1, s2, max);
//     printf("strnstr: %s\nft_strnstr: %s\n", i1,i2);
//     return (0);
// }
