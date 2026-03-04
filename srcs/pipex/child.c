/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:17:23 by memillet          #+#    #+#             */
/*   Updated: 2026/03/04 02:05:06 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	one_cmd(t_char *cmd, t_int *digit, char **envp, int i)
{
	dup2(digit->fd_inf, STDIN_FILENO);
	dup2(digit->fd_outf, STDOUT_FILENO);
	close(digit->fd_inf);
	close(digit->fd_outf);
	if (!cmd->cmdpth)
	{
		print_error("command error\n");
		exit(127);
	}
	execve(cmd->cmdpth[i], cmd->args[i], envp);
	print_error("Excve failed !");
	exit();
}

void	first_cmd(t_char *cmd, t_int *digit, char **envp, int i)
{
	dup2(digit->fd_inf, STDIN_FILENO);
	dup2(digit->curr_pipe[1], STDOUT_FILENO);
	close(digit->curr_pipe[0]);
	close(digit->curr_pipe[1]);
	close(digit->fd_inf);
	close(digit->fd_outf);
	if (!cmd->cmdpth)
	{
		print_error("first command error\n");
		exit(127);
	}
	execve(cmd->cmdpth[i], cmd->args[i], envp);
	print_error("Excve failed !");
	exit(127);
}

void	last_cmd(t_char *cmd, t_int *digit, char **envp, int i)
{
	dup2(digit->prev_pipe[0], STDIN_FILENO);
	dup2(digit->fd_outf, STDOUT_FILENO);
	close(digit->prev_pipe[0]);
	close(digit->prev_pipe[1]);
	close(digit->fd_inf);
	close(digit->fd_outf);
	if (!cmd->cmdpth)
	{
		print_error("last command error\n");
		exit(127);
	}
	execve(cmd->cmdpth[i], cmd->args[i], envp);
	print_error("Excve failed !");
	exit(127);
}

void	middle_cmd(t_char *cmd, t_int *digit, char **envp, int i)
{
	dup2(digit->prev_pipe[0], STDIN_FILENO);
	dup2(digit->curr_pipe[1], STDOUT_FILENO);
	close(digit->prev_pipe[0]);
	close(digit->prev_pipe[1]);
	close(digit->curr_pipe[0]);
	close(digit->curr_pipe[1]);
	close(digit->fd_inf);
	close(digit->fd_outf);
	if (!cmd->cmdpth)
	{
		print_error("command error\n");
		exit(127);
	}
	execve(cmd->cmdpth[i], cmd->args[i], envp);
	print_error("Excve failed !");
	exit(127);
}

void	choose_child(t_char *cmd, t_int *digit, char **envp, int i)
{
	if (digit->nbcmd == 1)
		one_cmd(cmd, digit, envp, i);
	else if (i == 0)
		first_cmd(cmd, digit, envp, i);
	else if (i == digit->nbcmd - 1)
		last_cmd(cmd, digit, envp, i);
	else
		middle_cmd(cmd, digit, envp, i);
}
