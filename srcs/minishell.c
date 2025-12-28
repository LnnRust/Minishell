/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 19:29:23 by aandreo           #+#    #+#             */
/*   Updated: 2025/12/28 00:29:47 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int main(void)
{
	char *input;
	while (1)
	{
		input = readline("minishell> ");
		if (!input)  // if user -> Ctrl+D ( = signal eof -> need to exit)
		{
			printf("successfully exited minishell\n");
			break;
		}
		if (*input)
			add_history(input);  // add_history allows to keep commands and navigate with up/down
		tokenizer(input);
		free(input);  // Readline allocates memory but doesnt free
	}
	return (0);
}
