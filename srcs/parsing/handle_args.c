/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 02:04:33 by fbenech           #+#    #+#             */
/*   Updated: 2026/03/03 05:08:50 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	count_args(t_token *token, t_info *info)
{
	t_token	*tmp;

	tmp = token;
	while (tmp && tmp->type != TOKEN_PIPE)
	{
		if (tmp->type == TOKEN_WORD)
			info->argc++;
		tmp = tmp->next;
	}
	return ;
}

int	alloc_args(t_info *info, t_token *token)
{
	count_args(token, info);
	info->args = malloc(sizeof(char *) * (info->argc + 10));
	if (!info->args)
		return (0);
	info->args[0] = NULL;
	return (1);
}
