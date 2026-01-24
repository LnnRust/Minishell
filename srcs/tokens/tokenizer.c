#include "../includes/Minishell.h"

//	this function return the token type base on value and length
static t_token_type get_type(char *value, int has_quotes)
{
	if (has_quotes) // -> if quote = always a word
	return (TOKEN_WORD);
	if (ft_strlen(value) == 1 && value[0] == '|')
	return (TOKEN_PIPE);
	if (ft_strlen(value) == 1 && value[0] == '<')
	return (TOKEN_REDIRECT_IN);
	if (ft_strlen(value) == 2 && value[0] == '<' && value[1] == '<')
	return (TOKEN_HEREDOC);
	if (ft_strlen(value) == 1 && value[0] == '>')
	return (TOKEN_REDIRECT_OUT);
	if (ft_strlen(value) == 2 && value[0] == '>' && value[1] == '>')
	return (TOKEN_APPEND);
	return (TOKEN_WORD);
}

//	return index of end of word to tokenize "token per token"
//	handled quotes with flags -> has_quotes / in_single / in_double
static int find_end_of_word(char *word, int *has_quotes)
{
	int i;
	int in_single;
	int in_double;

	i = 0;
	in_single = 0;
	in_double = 0;
	*has_quotes = 0;
	while(word[i])
	{
		if(word[i] == '\'' && !in_double)
		{
			in_single = !in_single;
			*has_quotes = 1;
		}
		else if(word[i] == '\"' && !in_single)
		{
			in_double = !in_double;
			*has_quotes = 1;
		}
		else if(!in_single && !in_double
			&& (is_space(word[i]) || word[i] == '|' || word[i] == '<' || word[i] == '>'))
			break;
			i++;
		}
		if(in_double || in_single)
		return (-1);
		return (i);
	}

	static int get_token_len(char *input, int *has_quotes)
	{
		*has_quotes = 0;

	// check if operator
	if (input[0] == '|')
	return (1);
	if (input[0] == '<')
	{
		if (input[1] == '<')
		return (2);
		return (1);
	}
	if (input[0] == '>')
	{
		if (input[1] == '>')
			return (2);
			return (1);
		}
		// if not == word -> need to find end of word
	return (find_end_of_word(input, has_quotes));
}

//	split input into tokens and return linked list of tokens
t_token *tokenizer(char *input)
{
	int		len;
	int		i = 0;
	int		has_quotes;
	char	*value;
	t_token	*tokens = NULL;
	t_token	*new;

	while(input[i])
	{
		while(is_space(input[i]))
			i++;
		if(!input[i])
			break;
		len = get_token_len(&input[i], &has_quotes);
		if (len < 0)
			return (printf("Unclosed quote\n"), free_tokens(tokens), NULL);
		value = ft_substr(input, i, len);
		if (!value)
			return (free_tokens(tokens), NULL);
		new = create_token(value, get_type(value, has_quotes));
		if (!new)
			return (free(value), free_tokens(tokens), NULL);
		token_addback(&tokens, new);
		i += len;
	}
	return (tokens);
}

