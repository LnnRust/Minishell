/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:27:57 by mehdi             #+#    #+#             */
/*   Updated: 2026/03/04 03:32:36 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_fd_out(t_rd *redir, t_int *digit)
{
	if (digit->fd_outf != STDOUT_FILENO)
		close(digit->fd_outf);
	if (redir->type == RD_OUT)
		digit->fd_outf = open(redir->file, O_WRONLY | O_CREAT
				| O_TRUNC, 0644);
	else
		digit->fd_outf = open(redir->file, O_WRONLY | O_CREAT
				| O_APPEND, 0644);
	if (digit->fd_outf < 0)
		perror(redir->file);
}

static void	ft_fd_heredoc(t_rd *redir, t_int *digit, t_envp *envp, t_shell *st)
{
	int	hres;

	if (digit->fd_inf != STDIN_FILENO)
		close(digit->fd_inf);
	hres = heredoc(redir->file, envp, digit, st);
	if (hres == -1)
		digit->fd_inf = -1;
	else
		digit->fd_inf = hres;
}

void	ft_fd(t_rd *redir, t_int *digit, t_envp *envp, t_shell *st)
{
	while (redir != NULL)
	{
		if (redir->type == RD_IN)
		{
			if (digit->fd_inf != STDIN_FILENO)
				close(digit->fd_inf);
			digit->fd_inf = open(redir->file, O_RDONLY);
			if (digit->fd_inf < 0)
				perror(redir->file);
		}
		else if (redir->type == RD_OUT || redir->type == RD_APPEND)
			ft_fd_out(redir, digit);
		else if (redir->type == HEREDOC)
			ft_fd_heredoc(redir, digit, envp, st);
		redir = redir->next;
	}
}

void	ft_built_in(t_info *info, t_envp *ev, t_shell *status)
{
	bool	ret;

	ret = true;
	if (info->built_in == CD)
		ret = builtin_cd(info->args, ev);
	else if (info->built_in == ECHO)
		ret = builtin_echo(info->args);
	else if (info->built_in == ENV)
		ret = builtin_env(ev);
	else if (info->built_in == EXIT)
		builtin_exit(info->args, status->exit_status, ev, status);
	else if (info->built_in == EXPORT)
		ret = builtin_export(ev, info->args);
	else if (info->built_in == PWD)
		ret = builtin_pwd();
	else if (info->built_in == UNSET)
		ret = builtin_unset(ev, info->args);
	if (ret)
		status->exit_status = 0;
	else
		status->exit_status = 1;
}

void	ft_exec(t_info *info, t_envp *ev, t_shell *status)
{
	t_int	*digit;

	digit = new_digit();
	status->digit = digit;
	if (!digit)
	{
		free_token(ev->first);
		free_info(info);
		return (free(ev->line));
	}
	digit->save_in = dup(STDIN_FILENO);
	digit->save_out = dup(STDOUT_FILENO);
	if (!info)
	{
		close(digit->save_in);
		close(digit->save_out);
		return (free(digit));
	}
	digit->nb_cmd = ft_lstsize(info);
	ft_do_exec(digit, ev, status);
	dup2(digit->save_in, STDIN_FILENO);
	dup2(digit->save_out, STDOUT_FILENO);
	close(digit->save_in);
	close(digit->save_out);
	free(digit);
}
