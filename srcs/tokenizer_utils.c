/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 19:57:51 by aandreo           #+#    #+#             */
/*   Updated: 2025/12/27 22:08:27 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

// help to skip spaces
int is_space(char c)
{
	if(c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

// return index of end of word to tokenize "token per token" 
int find_end_of_word(char *word)
{
	int i = 0;
	while(word[i] && !is_space(word[i]) && word[i] != '|' && word[i] != '<' && word[i] != '>')
		i++;
	return (i);
}
