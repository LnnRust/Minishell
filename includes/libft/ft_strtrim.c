/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 01:57:10 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:59:06 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @author AntonioBiscuit (ancourti)
// @brief Sub-function of `ft_strtrim()` made with <3 by ancourti.
// Finds where to trim the string from the begining, if possible, given the
// characters in `set`.
// @return - Beginning trim point position, if a trim point is found.
// @return - 0 if no trim point is found : the string will not be trimmed
// from the beginning by `ft_strtrim()`
static int	ft_find_trim_head(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				break ;
			}
			j++;
		}
		if (set[j] == '\0')
		{
			return (i);
		}
		i++;
	}
	return (i);
}

// @author AntonioBiscuit (ancourti)
// @brief Sub-function of `ft_strtrim()` made with <3 by ancourti.
// Finds where to trim the string from the end, if possible, given the
// characters in `set`.
// If a trim head point was found, `ft_find_trim_tail()` will not go
// past that point, as doing such will give a string made of only 1 char.
// @param s1 String to find a trim point in.
// @param set Set of characters used to detect a trim point.
// @param trim_head_pos Trim head found by running `ft_find_trim_head()`.
// @return - Tail trim point position, if a trim point is found.
// @return - `ft_str_len(s1)` if no trim point is found :
// the string will not be trimmed
// from the end by `ft_strtrim()`
static int	ft_find_trim_tail(char const *s1, char const *set,
		int trim_head_pos)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	while (i > trim_head_pos)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				break ;
			}
			j++;
		}
		if (set[j] == '\0')
		{
			return (i + 1);
		}
		i--;
	}
	return (ft_strlen(s1));
}

// @brief Allocates memory using `malloc()` and returns a
// copy of `s1` with characters from `set` removed
// from the beginning and the end.
// @param s1 The string to be trimmed.
// @param set The string containing the set of characters to be removed.
// @return (The trimmed string); or `NULL` if the allocation fails.
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	int		i;
	int		j;
	int		trim_head_pos;
	int		trim_tail_pos;

	trim_head_pos = ft_find_trim_head(s1, set);
	if (trim_head_pos == (int)ft_strlen(s1))
		return (ft_strdup(""));
	trim_tail_pos = ft_find_trim_tail(s1, set, trim_head_pos);
	trimmed_str = malloc((trim_tail_pos - trim_head_pos + 1) * sizeof(char));
	if (trimmed_str == NULL)
	{
		return (NULL);
	}
	i = trim_head_pos;
	j = 0;
	while (i < trim_tail_pos)
	{
		trimmed_str[j] = s1[i];
		j++;
		i++;
	}
	trimmed_str[j] = '\0';
	return (trimmed_str);
}
// "++___---+Dan-=iel_=--=-=="  "=-+_"

// int	main(void)
// {
// 	char *temp = ft_strtrim("        ", " ");
// 	printf("%s\n", temp);
// }
