/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 01:34:12 by fbenech           #+#    #+#             */
/*   Updated: 2026/03/03 06:16:26 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_right_n_operator(t_token *token, t_count *count)
{
	count->i = -1;
	while (token->token[++count->i])
	{
		if (is_open_bracket(token->token[count->i]))
			count->braquet++;
		else if (is_close_bracket(token->token[count->i]))
			count->braquet--;
		else if (is_simple_quote(token->token[count->i]))
			count->squotes++;
		else if (is_double_quotes(token->token[count->i]))
			count->dquotes++;
		else if (is_open_embrace(token->token[count->i]))
			count->embrace++;
		else if (is_close_embrace(token->token[count->i]))
			count->embrace--;
		else if (is_open_s_bracket(token->token[count->i]))
			count->square_brqt++;
		else if (is_close_s_braquet(token->token[count->i]))
			count->square_brqt--;
	}
	if (!count->braquet && !count->embrace && !count->square_brqt
		&& count->squotes % 2 == 0 && count->dquotes % 2 == 0)
		return (1);
	return (0);
}

int	check_syntaxe(t_envp *envp)
{
	t_token	*tmp;

	tmp = envp->first;
	if (tmp->type == TOKEN_PIPE)
		return (0);
	while (tmp->next)
	{
		if (tmp->type != TOKEN_WORD && tmp->next
			&& tmp->next->type != TOKEN_WORD)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->type != TOKEN_WORD)
		return (0);
	else
		return (1);
}

int	handle_syntax(t_envp *envp, t_count *count)
{
	envp->first = tokenizer(envp->line);
	if (!envp->first)
	{
		free(envp->line);
		free(count);
		return (0);
	}
	if (!check_syntaxe(envp))
	{
		ft_putstr_fd("minishell: syntax error\n", 2);
		free_token(envp->first);
		free(envp->line);
		free(count);
		return (0);
	}
	return (1);
}
