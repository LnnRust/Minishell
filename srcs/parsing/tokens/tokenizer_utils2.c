/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 07:19:28 by aandreo           #+#    #+#             */
/*   Updated: 2026/03/03 07:20:22 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	create_and_add(t_token **tokens, char *token, int has_quotes)
{
	t_token	*new;

	new = create_token(token, get_type(token, has_quotes));
	if (!new)
	{
		free(token);
		return (0);
	}
	token_addback(tokens, new);
	return (1);
}

int	is_separator(char c, int in_single, int in_double)
{
	if (in_single || in_double)
		return (0);
	return (is_space(c) || c == '|' || c == '<' || c == '>' || c == '*');
}

int	handle_quote_toggle(char c, int *in_single, int *in_double)
{
	if (c == '\'' && !(*in_double))
	{
		*in_single = !(*in_single);
		return (1);
	}
	if (c == '"' && !(*in_single))
	{
		*in_double = !(*in_double);
		return (1);
	}
	return (0);
}
