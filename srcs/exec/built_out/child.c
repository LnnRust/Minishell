/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:52:46 by memillet          #+#    #+#             */
/*   Updated: 2026/03/04 03:33:17 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	one_cmd(t_info *info, t_envp *ev, t_int *digit, t_shell *status)
{
	(void)status;
	dup2(digit->fd_inf, STDIN_FILENO);
	dup2(digit->fd_outf, STDOUT_FILENO);
	ft_close_call(digit);
	if (!info->cmd_pth)
	{
		if (info->args && info->args[0])
		{
			ft_putstr_fd("minishell: command not found: ", 2);
			ft_putstr_fd(info->args[0], 2);
			ft_putstr_fd("\n", 2);
		}
		return (127);
	}
	execve(info->cmd_pth, info->args, ev->env);
	perror("execve");
	return (127);
}

int	first_cmd(t_info *info, t_envp *ev, t_int *digit, t_shell *status)
{
	dup2(digit->fd_inf, STDIN_FILENO);
	if (digit->fd_outf != STDOUT_FILENO)
		dup2(digit->fd_outf, STDOUT_FILENO);
	else
		dup2(digit->curr_pipe[1], STDOUT_FILENO);
	ft_close_call(digit);
	if (info->built_in >= 0)
	{
		pipe_builtin(info, digit, ev, status);
		return (status->exit_status);
	}
	if (!info->cmd_pth)
	{
		if (info->args && info->args[0] && info->built_in < 0)
		{
			ft_putstr_fd("minishell: command not found: ", 2);
			ft_putstr_fd(info->args[0], 2);
			ft_putstr_fd("\n", 2);
		}
		return (127);
	}
	execve(info->cmd_pth, info->args, ev->env);
	perror("execve");
	return (127);
}

int	last_cmd(t_info *info, t_envp *ev, t_int *digit, t_shell *status)
{
	if (digit->fd_inf != STDIN_FILENO)
		dup2(digit->fd_inf, STDIN_FILENO);
	else
		dup2(digit->prev_pipe[0], STDIN_FILENO);
	dup2(digit->fd_outf, STDOUT_FILENO);
	ft_close_call(digit);
	if (info->built_in >= 0)
	{
		pipe_builtin(info, digit, ev, status);
		return (status->exit_status);
	}
	if (!info->cmd_pth)
	{
		if (info->args && info->args[0])
		{
			ft_putstr_fd("minishell: command not found: ", 2);
			ft_putstr_fd(info->args[0], 2);
			ft_putstr_fd("\n", 2);
		}
		return (127);
	}
	execve(info->cmd_pth, info->args, ev->env);
	perror("execve");
	return (127);
}

int	middle_cmd(t_info *info, t_envp *ev, t_int *digit, t_shell *status)
{
	if (digit->fd_inf != STDIN_FILENO)
		dup2(digit->fd_inf, STDIN_FILENO);
	else
		dup2(digit->prev_pipe[0], STDIN_FILENO);
	if (digit->fd_outf != STDOUT_FILENO)
		dup2(digit->fd_outf, STDOUT_FILENO);
	else
		dup2(digit->curr_pipe[1], STDOUT_FILENO);
	ft_close_call(digit);
	if (info->built_in >= 0)
	{
		pipe_builtin(info, digit, ev, status);
		return (status->exit_status);
	}
	if (!info->cmd_pth)
	{
		if (info->args && info->args[0])
			ft_putstr_fd("minishell: command not found\n", 2);
		return (127);
	}
	execve(info->cmd_pth, info->args, ev->env);
	perror("execve");
	return (127);
}

void	choose_child(t_info *info, t_envp *ev, t_int *digit, t_shell *status)
{
	int	ret;

	ret = 127;
	setup_child_signals();
	if (digit->nb_cmd == 1)
		ret = one_cmd(info, ev, digit, status);
	else if (digit->i == 0)
		ret = first_cmd(info, ev, digit, status);
	else if (digit->i == digit->nb_cmd - 1)
		ret = last_cmd(info, ev, digit, status);
	else
		ret = middle_cmd(info, ev, digit, status);
	free_child(ev, digit, status);
	exit(ret);
}
