/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:32:27 by memillet          #+#    #+#             */
/*   Updated: 2026/03/02 07:04:40 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <errno.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_int
{
	int		nbcmd;
	int		ac;
	int		path_i;
	int		id;
	int		curr_pipe[2];
	int		prev_pipe[2];
	int		fd_inf;
	int		fd_outf;
	pid_t	pid;
}	t_int;

typedef struct s_char
{
	char	**path;
	char	**all_cmd;
	char	**cmdb;
	char	**cmdpth;
	char	***args;
}	t_char;

//utils.c

int		print_error(char *msg);
char	*get_full_path(char *path, char *cmd);
void	malloc_struct(t_char *cmd, t_int *digit);
void	free_tab(char **s);
void	clear_master(t_char *cmd, t_int *digit);

//cmd.c

void	get_cmd(t_char *cmd, t_int *digit, char **av);
char	*cmd_path(char *cmd, char **path);
char	**get_all_path(char **envp);
char	*split_cmd(char *cmd);
char	*cmd_path(char *cmd, char **path);

//child.c

void	choose_child(t_char *cmd, t_int *digit, char **envp, int i);
void	middle_cmd(t_char *cmd, t_int *digit, char **envp, int i);
void	last_cmd(t_char *cmd, t_int *digit, char **envp, int i);
void	first_cmd(t_char *cmd, t_int *digit, char **envp, int i);
void	one_cmd(t_char *cmd, t_int *digit, char **envp, int i);

#endif
