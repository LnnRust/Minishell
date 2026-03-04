/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator_p_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:36:30 by fbenech           #+#    #+#             */
/*   Updated: 2026/01/31 18:36:54 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_double_quotes(char c)
{
	return (c == 34);
}

int	is_double_ampersand(char *c, int i)
{
	return (c[i] == '&' && c[i + 1] == '&');
}

int	is_pipe(char c)
{
	return (c == '|');
}

int	is_double_pipe(char *c, int i)
{
	return (c[i] == '|' && c[i + 1] == '|');
}

int	is_heredoc(char *c, int i)
{
	return (c[i] == '<' && c[i + 1] == '<');
}
