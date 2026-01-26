#include "../includes/Minishell.h"

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
