/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:40:26 by fbenech           #+#    #+#             */
/*   Updated: 2026/03/03 05:21:45 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirection(t_token *token, t_info *info)
{
	if (token->type == TOKEN_REDIRECT_IN)
	{
		info->type = RD_IN;
		new_rd_lst(&info->first_redirs, token->next->token, RD_IN);
		return (1);
	}
	else if (token->type == TOKEN_REDIRECT_OUT)
	{
		info->type = RD_OUT;
		new_rd_lst(&info->first_redirs, token->next->token, RD_OUT);
		return (1);
	}
	else if (token->type == TOKEN_APPEND)
	{
		info->type = RD_APPEND;
		new_rd_lst(&info->first_redirs, token->next->token, RD_APPEND);
		return (1);
	}
	else if (token->type == TOKEN_HEREDOC)
	{
		info->type = HEREDOC;
		new_rd_lst(&info->first_redirs, token->next->token, HEREDOC);
		return (1);
	}
	return (0);
}

int	big_loop(t_token **token, t_count *count, t_envp *envp, t_info **info)
{
	if (!is_right_n_operator(*token, count))
		return (ft_putstr_fd("minishell: syntax error\n", 2), 0);
	expand(*token, envp->env_list, envp->exit_status);
	if ((*token)->type == TOKEN_WORD)
		if (!is_token_cmd(envp, *token, *info))
			(*info)->args[(*info)->i++] = ft_strdup((*token)->token);
	if (redirection(*token, *info))
	{
		if ((*token)->next)
			*token = (*token)->next;
		return (1);
	}
	if ((*token)->type == TOKEN_PIPE)
	{
		(*info)->args[(*info)->i++] = NULL;
		(*info)->next = new_info();
		if ((*token)->next)
			alloc_args((*info)->next, (*token)->next);
		*info = (*info)->next;
	}
	else if ((*token)->type == TOKEN_HEREDOC)
		if (!handle_heredoc_tok(token, info))
			return (0);
	return (1);
}

void	new_rd_lst(t_rd **first_rd, char *file, t_rd_type type)
{
	t_rd	*new;

	new = malloc(sizeof(t_rd));
	new->file = ft_strdup(file);
	new->type = type;
	new->next = NULL;
	add_rd_back(first_rd, new);
	return ;
}

void	add_rd_back(t_rd **rd, t_rd *new)
{
	if (!*rd)
		*rd = new;
	else
		last_rd(*rd)->next = new;
}

t_rd	*last_rd(t_rd *rd)
{
	if (!rd)
		return (NULL);
	while (rd->next)
		rd = rd->next;
	return (rd);
}
