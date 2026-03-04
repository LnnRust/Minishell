/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:32:12 by memillet          #+#    #+#             */
/*   Updated: 2026/03/02 07:04:48 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent(t_int *digit, int i)
{
	int	status;

	close(digit->curr_pipe[1]);
	if (i > 0)
	{
		close(digit->prev_pipe[0]);
	}
	digit->prev_pipe[0] = digit->curr_pipe[0];
	digit->prev_pipe[1] = digit->curr_pipe[1];
	waitpid(digit->pid, &status, 0);
	if (i == digit->nbcmd - 1)
	{
		close(digit->curr_pipe[0]);
		close(digit->fd_inf);
		close(digit->fd_outf);
	}
}

void	exec(t_char *cmd, t_int *digit, char **envp)
{
	int	i;

	i = 0;
	digit->prev_pipe[0] = -1;
	digit->prev_pipe[1] = -1;
	while (i < digit->nbcmd)
	{
		pipe(digit->curr_pipe);
		digit->pid = fork();
		if (digit->pid == 0)
		{
			choose_child(cmd, digit, envp, i);
			exit(127);
		}
		else
			parent(digit, i);
		i++;
	}
}

void	init_struct(t_char *cmd, t_int *digit, char **av, char **envp)
{
	int	j;

	j = -1;
	digit->fd_inf = open(av[1], O_RDONLY);
	if (digit->fd_inf < 0)
		print_error("wrong infile");
	digit->fd_outf = open(av[digit->ac - 1], 01 | O_CREAT | O_TRUNC, 0664);
	if (digit->fd_outf < 0)
	{
		close(digit->fd_inf);
		print_error("Error on outfile");
	}
	malloc_struct(cmd, digit);
	get_cmd(cmd, digit, av);
	cmd->path = get_all_path(envp);
	if (!cmd->path)
		print_error("no environment variable\n");
	while (++j < digit->nbcmd)
	{
		cmd->args[j] = ft_split(cmd->all_cmd[j], ' ');
		cmd->cmdb[j] = split_cmd(cmd->all_cmd[j]);
		cmd->cmdpth[j] = cmd_path(cmd->cmdb[j], cmd->path);
	}
	cmd->cmdb[j] = NULL;
	cmd->cmdpth[j] = NULL;
}

int	main(int ac, char **av, char **envp)
{
	t_char	*cmd;
	t_int	*digit;

	digit = malloc(sizeof(t_int));
	if (!digit)
		return (1);
	cmd = malloc(sizeof(t_char));
	if (!cmd)
		return (free(digit), 1);
	if (ac >= 4)
	{
		digit->ac = ac;
		digit->nbcmd = ac - 3;
		init_struct(cmd, digit, av, envp);
		exec(cmd, digit, envp);
		free_tab(cmd->all_cmd);
		clear_master(cmd, digit);
	}
	return (0);
}
