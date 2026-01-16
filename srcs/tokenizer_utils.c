#include "../includes/Minishell.h"

/// @brief Detect if a character is a "space", according to the ISO C standard.
/// The characters considered as "space" are  the following :
/// `' '`, `\t`, `\n` , `\v`, `\f` and `\r`.
/// @param c character to check.
/// @return 1 if the character is a space, 0 if it is not.
int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

// return index of end of word to tokenize "token per token"
// handled quotes with flags to
int	find_end_of_word(char *word)
{
	int		i;
	bool	in_single_quote;
	bool	in_double_quote;

	i = 0;
	in_single_quote = false;
	in_double_quote = false;
	while (word[i])
	{
		if (word[i] == '\'' && !in_double_quote)
			in_single_quote = !in_single_quote;
		else if (word[i] == '\"' && !in_single_quote)
			in_double_quote = !in_double_quote;
		else if ((!in_single_quote && !in_double_quote) && (ft_is_space(word[i])
				|| word[i] == '|' || word[i] == '<' || word[i] == '>'))
			break ;
		i++;
	}
	if (in_double_quote || in_single_quote)
		return (printf("Error: unclosed quote\n"), EXIT_FAILURE);
	// unclosed quote
	return (i);
}

// char	*ft_strdup(const char *src)
// {
// 	size_t	len;
// 	char	*dest;
// 	size_t	i;

// 	len = 0;
// 	while (src[len])
// 		len++;
// 	dest = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!dest)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	char	*newstring;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	if (start >= ft_strlen(s))
// 	{
// 		newstring = malloc(sizeof(char));
// 		if (!newstring)
// 			return (NULL);
// 		newstring[0] = '\0';
// 		return (newstring);
// 	}
// 	if (len > ft_strlen(s + start))
// 		len = ft_strlen(s + start);
// 	newstring = malloc((len + 1) * sizeof(char));
// 	if (!newstring)
// 		return (NULL);
// 	while (s[start] && i < len)
// 		newstring[i++] = s[start++];
// 	newstring[i] = '\0';
// 	return (newstring);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	return (len);
// }
