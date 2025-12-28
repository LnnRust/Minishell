/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:46:01 by aandreo           #+#    #+#             */
/*   Updated: 2025/12/28 02:06:39 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

//split input into tokens and prints them (atm)
//TODO need to add -> create linked list and fill tokens in it
//TODO			   -> handle special tokens | < > >>
//TODO			   -> handle quotes ('' && "")
//TODO			   -> handle escape characters
void tokenizer(char *input)
{
	int len;
	int i;
	int j;

	i = 0;
	while(input[i])
	{
		while(is_space(input[i]))
			i++;
		if(!input[i])
			break;
		if (input[i] == '|')
		{
			printf("Token [PIPE]\n");
			i++;
			continue;
		}
		if (input[i] == '>' && input[i + 1] == '>')
		{
			printf("Token [APPEND >>]\n");
			i += 2;
			continue;
		}
		if (input[i] == '>')
		{
			printf("Token [REDIRECT_OUT >]\n");
			i++;
			continue;
		}
		if (input[i] == '<' && input[i + 1] == '<')
		{
			printf("Token [HEREDOC <<]\n");
			i += 2;
			continue;
		}
		if (input[i] == '<')
		{
			printf("Token [REDIRECT_IN <]\n");
			i++;
			continue;
		}
		len = find_end_of_word(&input[i]);
		j = 0;
		while(j < len)
		{
			printf("%c", input[i + j]);
			j++;
		}
		printf(" ");
		i += len;
	}
	printf("\n");
}
