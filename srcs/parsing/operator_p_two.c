/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_p_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:34:50 by fbenech           #+#    #+#             */
/*   Updated: 2026/03/03 05:20:47 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_rd_out(char *c, int i)
{
	return (c[i] == '>' && c[i + 1] == '>');
}

int	is_overwrite(char *c, int i)
{
	return (c[i] == '>' && c[i + 1] != '>');
}

int	is_rd_in(char *c, int i)
{
	return (c[i] == '<' && c[i + 1] != '<');
}

int	is_open_bracket(char c)
{
	return (c == '(');
}

int	is_close_bracket(char c)
{
	return (c == ')');
}
