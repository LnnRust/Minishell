/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 23:45:14 by ancourti          #+#    #+#             */
/*   Updated: 2026/01/19 07:16:07 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// @brief Counts words in string `s` using character `sep` as
// delimiter for words.
// @return Number of "words" in string `s`
static int	ft_cnt_w(char const *s, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (s[i] == '\0')
		return (words);
	while (s[i] == sep && s[i] != '\0')
		i++;
	if (s[i] != '\0')
		words++;
	while (s[i] != '\0')
	{
		if (s[i] == sep)
		{
			while (s[i] == sep && s[i] != '\0')
				i++;
			if (s[i] == '\0')
				return (words);
			words++;
		}
		i++;
	}
	return (words);
}

// @brief Sub-function of `ft_split()`.
// @param src Source string.
// @param destination_str Destination string as `dst[x][y]`.
// @param src_start_index Should exclude (be after) separator.
// @param src_end_index Should exclude (be before) `'\0'`.
// @param word_index The word index in the array of pointers.
// If you wish to change the first word in the array, pass '0'.
static void	ft_fill_word(char const *src, char *destination_str,
		int src_start_index, int src_end_index)
{
	int	i;
	int	j;

	i = 0;
	j = src_start_index;
	while (i < src_end_index - src_start_index)
	{
		destination_str[i] = src[j];
		i++;
		j++;
	}
	destination_str[i] = '\0';
}

// Use this to skip separators from given string.
// @return Position where there is no more sep,
// Either the start of a word, or the end of the string.
// @param i Start skipping sep from index i.
// @param src_string Pointer to source string.
// @param sep Separator char.
static int	ft_skip_seps(int *i, const char *src_string, char sep)
{
	while (src_string[*i] == sep && src_string[*i] != '\0')
		(*i)++;
	return (*i);
}

static void	free_all(char **array_of_ptr)
{
	int	i;

	i = 0;
	while (array_of_ptr[i])
	{
		free(array_of_ptr[i]);
		i++;
	}
	free(array_of_ptr);
}

/// @brief Allocates memory using `malloc()` and returns an
/// array of strings obtained by splitting `s` using
/// the character `c` as a delimiter. The array must
/// end with a NULL pointer.
/// @param s The string to be split.
/// @param separator The delimiter character.
/// @return - The array of new strings resulting from the split.
/// @return - NULL if the allocation fails.
char	**ft_split(char const *s, char sep)
{
	char	**array_of_ptr;
	int		i;
	int		j;
	int		prev_w_pos;

	array_of_ptr = malloc(sizeof(char *) * (ft_cnt_w(s, sep)) + sizeof(NULL));
	if (array_of_ptr == NULL)
		return (NULL);
	i = 0;
	prev_w_pos = ft_skip_seps(&i, s, sep);
	j = 0;
	while (j < ft_cnt_w(s, sep))
	{
		if (s[i] == sep || i == (int)ft_strlen(s))
		{
			array_of_ptr[j] = malloc(sizeof(char) * (i - prev_w_pos + 1));
			if (array_of_ptr[j] == NULL)
				return (free_all(array_of_ptr), NULL);
			ft_fill_word(s, array_of_ptr[j++], prev_w_pos, i);
			prev_w_pos = ft_skip_seps(&i, s, sep);
		}
		else
			i++;
	}
	return (array_of_ptr[j] = NULL, array_of_ptr);
}

// int	main(void)
// {
// 	// ft_split("   lorem   ipsum dolor     sit amet, consectetu r ", 'z');

// 	char **temp = ft_split("hello!", ' ');
// 	// ft_split("xxxxxxxxhello!", 'x');
// 	// char ** temp = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
// 	int i = 0;
// 	while (temp[i])
// 	{
// 		printf("%s\n", temp[i]);
// 		free(temp[i]);
// 		i++;
// 	}
// 	// free(temp);
// 	//ft_split("", 'a');
// }
