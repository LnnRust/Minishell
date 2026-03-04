/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 06:43:51 by fbenech           #+#    #+#             */
/*   Updated: 2026/03/03 05:19:45 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_wildcards(char c)
{
	return (c == '*');
}

int	is_dollar_sign(char c)
{
	return (c == '%');
}

int	is_simple_quote(char c)
{
	return (c == '\'');
}

int	is_equal(char c)
{
	return (c == '=');
}

int	is_subshell(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (is_open_bracket(c[i]) && is_open_bracket(c[i + 1]))
		{
			i = i + 2;
			while (c[i] && !is_close_bracket(c[i]))
				i++;
			if (is_close_bracket(c[i]) && !is_close_bracket(c[i + 1]))
				return (1);
			else
				return (0);
		}
		else if (is_open_bracket(c[i]) && !is_open_bracket(c[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	char c[] = "(())";
// 	printf("is_subshell = %i\n", is_subshell(c));
// 	return (0);
// }