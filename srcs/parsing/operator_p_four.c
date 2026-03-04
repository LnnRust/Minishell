/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_p_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:50:07 by fbenech           #+#    #+#             */
/*   Updated: 2026/03/03 05:20:20 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_slash(char c)
{
	return (c == '/');
}

int	is_open_s_bracket(char c)
{
	return (c == '[');
}

int	is_close_s_braquet(char c)
{
	return (c == ']');
}

int	is_open_embrace(char c)
{
	return (c == '{');
}

int	is_close_embrace(char c)
{
	return (c == '}');
}
