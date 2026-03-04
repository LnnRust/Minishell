/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:27:54 by memillet          #+#    #+#             */
/*   Updated: 2026/03/04 00:16:58 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*expand_line(char *tmp, int expand, t_envp *ev)
{
	char	*expanded;

	if (!expand || !ft_strchr(tmp, '$'))
		return (tmp);
	expanded = expand_heredoc(tmp, ev->env_list, ev);
	if (expanded)
	{
		free(tmp);
		return (expanded);
	}
	return (tmp);
}

static void	heredoc_write(int fd, char *tmp, int expand, t_envp *ev)
{
	tmp = expand_line(tmp, expand, ev);
	ft_putstr_fd(tmp, fd);
	ft_putchar_fd('\n', fd);
	free(tmp);
}

static void	heredoc_child(int fd, char *del, t_envp *ev, t_hd_ctx *ctx)
{
	char	*tmp;
	char	*clean_del;
	int		expand;

	g_signal = 0;
	setup_heredoc(del, &clean_del, &expand);
	while (1)
	{
		tmp = readline("heredoc> ");
		if (g_signal)
		{
			if_signals(fd, tmp, clean_del);
			free_child(ev, ctx->dgt, ctx->st);
			exit(130);
		}
		if (!tmp || is_delimiter(tmp, clean_del))
		{
			if_signals(fd, tmp, clean_del);
			free_child(ev, ctx->dgt, ctx->st);
			exit(0);
		}
		heredoc_write(fd, tmp, expand, ev);
	}
}

int	make_fd_read(int status)
{
	int	fd_read;

	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		unlink("/tmp/.minishell_heredoc");
		g_signal = SIGINT;
		return (-1);
	}
	fd_read = open("/tmp/.minishell_heredoc", O_RDONLY);
	unlink("/tmp/.minishell_heredoc");
	if (fd_read == -1)
		return (ft_putstr_fd("minishell: heredoc: failed to reopen\n", 2), -1);
	return (fd_read);
}

int	heredoc(char *delimeter, t_envp *envp, t_int *digit, t_shell *st)
{
	int			fd;
	pid_t		pid;
	int			wstatus;
	t_hd_ctx	ctx;

	ctx.dgt = digit;
	ctx.st = st;
	fd = open("/tmp/.minishell_heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		return (ft_putstr_fd("minishell: heredoc: failed to open tmp\n"
				, 2), -1);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == -1)
	{
		close(fd);
		unlink("/tmp/.minishell_heredoc");
		signal(SIGINT, handle_sigint);
		return (ft_putstr_fd("minishell: fork failed\n", 2), -1);
	}
	if (pid == 0)
		heredoc_child(fd, delimeter, envp, &ctx);
	waitpid(pid, &wstatus, 0);
	signal(SIGINT, handle_sigint);
	return (close(fd), make_fd_read(wstatus));
}
