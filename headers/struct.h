/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:52:58 by memillet          #+#    #+#             */
/*   Updated: 2026/03/04 01:08:52 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "minishell.h"
#include <stdbool.h>
#include <limits.h>
#include <unistd.h>
#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/stat.h>

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_HEREDOC,
	TOKEN_APPEND,
}	t_token_type;

typedef enum e_built_in
{
	ECHO = 1,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
}	t_built_in;

typedef enum e_rd_type
{
	RD_IN,
	RD_OUT,
	RD_APPEND,
	HEREDOC,
}	t_rd_type;

typedef struct s_rd
{
	t_rd_type		type;
	char			*file;
	struct s_rd		*next;
}	t_rd;

typedef struct s_count
{
	int		i;
	int		braquet;
	int		squotes;
	int		dquotes;
	int		square_brqt;
	int		embrace;
}	t_count;

typedef struct s_token
{
	char			*token;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

typedef struct s_envp
{
	int				exit_status;
	struct s_info	*i_first;
	struct s_token	*first;
	struct s_env	*env_list;
	char			**env;
	char			**path;
	char			*line;
}	t_envp;

typedef struct s_info
{
	int				i;
	char			**args;
	char			*cmd_pth;
	int				built_out;
	int				built_in;
	int				argc;
	t_rd			*first_redirs;
	t_rd_type		type;
	struct s_info	*next;
}	t_info;

typedef struct s_int
{
	int		save_in;
	int		save_out;
	int		i;
	int		nb_cmd;
	int		curr_pipe[2];
	int		prev_pipe[2];
	int		fd_inf;
	int		fd_outf;
	pid_t	pid;
	pid_t	*pids;
	int		last_status;
}	t_int;

typedef struct s_shell
{
	t_envp	*env;
	int		exit_status;
	bool	running;
	t_int	*digit;
}	t_shell;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_expand
{
	char	*str;
	char	*result;
	t_env	*env;
	int		exit_status;
	int		i;
	int		j;
	bool	in_single;
	bool	in_double;
}	t_expand;

typedef struct s_hd_ctx
{
	t_int	*dgt;
	t_shell	*st;
}	t_hd_ctx;
