/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:14:01 by memillet          #+#    #+#             */
/*   Updated: 2026/03/04 06:56:32 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	ft_help_fd(t_int *digit)
{
	if (digit->fd_inf != STDIN_FILENO)
		close(digit->fd_inf);
	if (digit->fd_outf != STDOUT_FILENO)
		close(digit->fd_outf);
	digit->fd_inf = STDIN_FILENO;
	digit->fd_outf = STDOUT_FILENO;
	dup2(digit->save_in, STDIN_FILENO);
	dup2(digit->save_out, STDOUT_FILENO);
}

static void	ft_call_builtin(t_info *cur, t_int *dgt, t_envp *ev, t_shell *tus)
{
	if (cur->built_in >= 0 && dgt->nb_cmd == 1)
		pipe_builtin(cur, dgt, ev, tus);
	else
		ft_error(dgt, cur, tus);
}

static void	ft_check_fd(t_int *dgt, t_info *cur, t_envp *ev, t_shell *tus)
{
	if (!cur->args || !cur->args[0])
	{
		ft_help_fd(dgt);
		return ;
	}
	ft_call_builtin(cur, dgt, ev, tus);
	ft_help_fd(dgt);
}

void	ft_do_exec(t_int *dgt, t_envp *ev, t_shell *tus)
{
	t_info	*cur;

	cur = ev->i_first;
	while (cur != NULL)
	{
		if (cur->built_out > 0
			|| (cur->built_in >= 0 && dgt->nb_cmd > 1))
		{
			ft_start(cur, dgt, ev, tus);
			break ;
		}
		ft_fd(cur->first_redirs, dgt, ev, tus);
		if (dgt->fd_inf < 0 || dgt->fd_outf < 0)
		{
			tus->exit_status = 1;
			ft_help_fd(dgt);
			return ;
		}
		ft_check_fd(dgt, cur, ev, tus);
		cur = cur->next;
	}
}

void	ft_start(t_info *info, t_int *digit, t_envp *ev, t_shell *status)
{
	digit->nb_cmd = ft_lstsize(info);
	if (digit->fd_outf != STDOUT_FILENO)
		dup2(digit->fd_outf, STDOUT_FILENO);
	ft_built_out(info, digit, ev, status);
	status->exit_status = digit->last_status;
}
