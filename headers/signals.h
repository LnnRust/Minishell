/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 07:02:24 by aandreo           #+#    #+#             */
/*   Updated: 2026/03/03 23:43:56 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <signal.h>

void	setup_parent_signals(void);
void	setup_child_signals(void);
void	handle_sigint(int sig);
void	handle_sigint_heredoc(int sig);

extern volatile sig_atomic_t	g_signal;
