/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 06:50:21 by aandreo           #+#    #+#             */
/*   Updated: 2026/03/03 07:21:07 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	this function return the token type base on token and length
t_token_type	get_type(char *token, int has_quotes)
{
	if (has_quotes)
		return (TOKEN_WORD);
	if (ft_strlen(token) == 1 && token[0] == '|')
		return (TOKEN_PIPE);
	if (ft_strlen(token) == 1 && token[0] == '<')
		return (TOKEN_REDIRECT_IN);
	if (ft_strlen(token) == 2 && token[0] == '<' && token[1] == '<')
		return (TOKEN_HEREDOC);
	if (ft_strlen(token) == 1 && token[0] == '>')
		return (TOKEN_REDIRECT_OUT);
	if (ft_strlen(token) == 2 && token[0] == '>' && token[1] == '>')
		return (TOKEN_APPEND);
	return (TOKEN_WORD);
}

//	return index of end of word to tokenize "token per token"
//	handled quotes with flags -> has_quotes / in_single / in_double
static int	find_end_of_word(char *word, int *has_quotes)
{
	int	i;
	int	in_single;
	int	in_double;

	i = 0;
	in_single = 0;
	in_double = 0;
	*has_quotes = 0;
	while (word[i])
	{
		if (handle_quote_toggle(word[i], &in_single, &in_double))
			*has_quotes = 1;
		else if (is_separator(word[i], in_single, in_double))
			break ;
		i++;
	}
	if (in_double || in_single)
		return (-1);
	return (i);
}

static int	get_token_len(char *input, int *has_quotes)
{
	*has_quotes = 0;
	if (input[0] == '\'' || input[0] == '"')
		return (find_end_of_word(input, has_quotes));
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
	return (find_end_of_word(input, has_quotes));
}

static int	process_token(char *input, int *i, t_token **tokens)
{
	int		len;
	int		has_quotes;
	char	*token;

	if (is_wildcards(input[*i]))
		return (printf("Parse error %s !\n", input), 0);
	len = get_token_len(&input[*i], &has_quotes);
	if (len < 0)
		return (printf("Quote error\n"), 0);
	token = ft_substr(input, *i, len);
	if (!token || !create_and_add(tokens, token, has_quotes))
		return (0);
	*i += len;
	return (1);
}

//	split input into tokens and return linked list of tokens
t_token	*tokenizer(char *input)
{
	int		i;
	t_token	*tokens;

	tokens = NULL;
	i = 0;
	while (input[i])
	{
		while (is_space(input[i]))
			i++;
		if (!input[i])
			break ;
		if (!process_token(input, &i, &tokens))
			return (free_tokens(tokens), NULL);
	}
	return (tokens);
}
