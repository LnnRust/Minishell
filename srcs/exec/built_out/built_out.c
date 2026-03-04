/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:43:33 by memillet          #+#    #+#             */
/*   Updated: 2026/03/03 23:46:39 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parent(t_int *digit, int i)
{
	int	status;

	close(digit->curr_pipe[1]);
	waitpid(digit->pid, &status, 0);
	if (i > 0)
		close(digit->prev_pipe[0]);
	digit->prev_pipe[0] = digit->curr_pipe[0];
	digit->prev_pipe[1] = digit->curr_pipe[1];
	if (WIFEXITED(status))
		digit->last_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		digit->last_status = 128 + WTERMSIG(status);
		if (WTERMSIG(status) == SIGQUIT)
			ft_putstr_fd("Quit (core dumped)\n", 2);
		else if (WTERMSIG(status) == SIGINT)
			ft_putchar_fd('\n', 2);
	}
	if (i == digit->nb_cmd - 1)
	{
		close(digit->curr_pipe[0]);
		close(digit->fd_inf);
		close(digit->fd_outf);
	}
}

static pid_t	*first_init(t_int *digit)
{
	pid_t	*pids;

	pids = malloc(sizeof(pid_t) * digit->nb_cmd);
	if (!pids)
		return (NULL);
	digit->i = 0;
	digit->prev_pipe[0] = -1;
	digit->prev_pipe[1] = -1;
	return (pids);
}

static void	ft_end(t_int *digit, pid_t *pids)
{
	int	status;

	digit->i = 0;
	while (digit->i < digit->nb_cmd)
	{
		waitpid(pids[digit->i], &status, 0);
		digit->i++;
	}
	if (WIFEXITED(status))
		digit->last_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		digit->last_status = 128 + WTERMSIG(status);
		if (WTERMSIG(status) == SIGQUIT)
			ft_putstr_fd("Quit (core dumped)\n", 2);
		else if (WTERMSIG(status) == SIGINT)
			ft_putchar_fd('\n', 2);
	}
	free(pids);
}

static void	ft_setup_and_fork(t_info *tmp, t_int *digit,
	t_envp *envp, t_shell *stats)
{
	if (digit->i < digit->nb_cmd - 1)
		pipe(digit->curr_pipe);
	else
	{
		digit->curr_pipe[0] = -1;
		digit->curr_pipe[1] = -1;
	}
	digit->pids[digit->i] = fork();
	if (digit->pids[digit->i] == 0)
	{
		free(digit->pids);
		digit->pids = NULL;
		choose_child(tmp, envp, digit, stats);
	}
	if (digit->i < digit->nb_cmd - 1)
		ft_close(digit);
	else if (digit->i > 0)
		close(digit->prev_pipe[0]);
}

void	ft_built_out(t_info *info, t_int *digit, t_envp *envp, t_shell *stats)
{
	t_info	*tmp;

	digit->pids = first_init(digit);
	if (!digit->pids)
		return ;
	tmp = info;
	while (tmp && digit->i < digit->nb_cmd)
	{
		if (tmp->args && tmp->args[0])
			tmp->cmd_pth = cmd_path(tmp->args[0], envp->path);
		else
			tmp->cmd_pth = NULL;
		ft_fd(tmp->first_redirs, digit, envp, stats);
		ft_setup_and_fork(tmp, digit, envp, stats);
		if (digit->fd_inf != STDIN_FILENO)
			close(digit->fd_inf);
		if (digit->fd_outf != STDOUT_FILENO)
			close(digit->fd_outf);
		digit->fd_inf = STDIN_FILENO;
		digit->fd_outf = STDOUT_FILENO;
		digit->i++;
		tmp = tmp->next;
	}
	ft_end(digit, digit->pids);
}
