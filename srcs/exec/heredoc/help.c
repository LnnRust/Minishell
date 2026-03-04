/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:06:09 by memillet          #+#    #+#             */
/*   Updated: 2026/03/04 00:15:51 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setup_heredoc(char *del, char **clean, int *expand)
{
	*expand = !has_quoted_delimiter(del);
	*clean = strip_quotes(del);
	signal(SIGINT, handle_sigint_heredoc);
	signal(SIGQUIT, handle_sigint_heredoc);
}

void	if_signals(int fd, char *tmp, char *clean_del)
{
	free(tmp);
	free(clean_del);
	close(fd);
}
