/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 01:40:20 by fbenech           #+#    #+#             */
/*   Updated: 2026/03/04 00:10:39 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

/*global var to keep latest signal*/
volatile sig_atomic_t	g_signal = 0;

/* ctrl + c handler (in parent)*/
/*tell readline -> new line*/
// clear buffer
//write prompt
void	handle_sigint(int sig)
{
	g_signal = sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

// sign setup for parent pro
// Ctrl+C -> call handle_sigintcesses (shell)
// Ctrl+\ -> sig_ign = ignore
void	setup_parent_signals(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}

// sign setup for child processes
// die	
// die + core dump
void	setup_child_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGPIPE, SIG_DFL);
}

void	handle_sigint_heredoc(int sig)
{
	(void)sig;
	g_signal = 1;
	write(1, "\n", 1);
	rl_done = 1;
}
