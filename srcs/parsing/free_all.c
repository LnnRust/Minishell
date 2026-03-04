/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 19:30:26 by fbenech           #+#    #+#             */
/*   Updated: 2026/03/04 03:37:23 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_token(t_token *token)
{
	t_token	*tmp;

	while (token)
	{
		tmp = token->next;
		if (token->token)
			free(token->token);
		free(token);
		token = tmp;
	}
}

void	free_redirs(t_rd *redirs)
{
	t_rd	*tmp;

	while (redirs)
	{
		tmp = redirs;
		redirs = redirs->next;
		free(tmp->file);
		free(tmp);
	}
}

void	free_info(t_info *info)
{
	int		i;
	t_info	*tmp;

	while (info)
	{
		tmp = info;
		info = info->next;
		i = 0;
		if (tmp->args)
		{
			while (tmp->args[i])
			{
				free(tmp->args[i]);
				i++;
			}
			free(tmp->args);
		}
		if (tmp->cmd_pth)
			free(tmp->cmd_pth);
		if (tmp->first_redirs)
			free_redirs(tmp->first_redirs);
		free(tmp);
	}
}

void	free_child(t_envp *ev, t_int *digit, t_shell *status)
{
	if (ev)
		free_me(&ev);
	if (digit)
	{
		if (digit->fd_inf > STDERR_FILENO)
			close(digit->fd_inf);
		if (digit->fd_outf > STDERR_FILENO)
			close(digit->fd_outf);
		if (digit->save_in > STDERR_FILENO)
			close(digit->save_in);
		if (digit->save_out > STDERR_FILENO)
			close(digit->save_out);
		if (digit->prev_pipe[0] > STDERR_FILENO)
			close(digit->prev_pipe[0]);
		if (digit->prev_pipe[1] > STDERR_FILENO)
			close(digit->prev_pipe[1]);
		if (digit->curr_pipe[0] > STDERR_FILENO)
			close(digit->curr_pipe[0]);
		if (digit->curr_pipe[1] > STDERR_FILENO)
			close(digit->curr_pipe[1]);
		free(digit->pids);
		free(digit);
	}
	free(status);
}

void	free_env_list(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		if (env->key)
			free(env->key);
		if (env->value)
			free(env->value);
		free(env);
		env = tmp;
	}
}
