/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:40:47 by memillet          #+#    #+#             */
/*   Updated: 2026/03/04 00:11:19 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close_call(t_int *digit)
{
	if (digit->fd_inf != STDIN_FILENO)
		close(digit->fd_inf);
	if (digit->fd_outf != STDOUT_FILENO)
		close(digit->fd_outf);
	close(digit->save_in);
	close(digit->save_out);
	if (digit->prev_pipe[0] != -1)
		close(digit->prev_pipe[0]);
	if (digit->prev_pipe[1] != -1)
		close(digit->prev_pipe[1]);
	if (digit->curr_pipe[0] != -1)
		close(digit->curr_pipe[0]);
	if (digit->curr_pipe[1] != -1)
		close(digit->curr_pipe[1]);
}

char	**get_all_path(char **envp)
{
	char	*tmp;
	char	**path;
	int		i;

	i = -1;
	tmp = NULL;
	if (!envp[0])
		return (NULL);
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			tmp = envp[i] + 5;
			break ;
		}
	}
	if (!tmp)
		return (NULL);
	path = ft_split(tmp, ':');
	if (!path)
		return (NULL);
	return (path);
}

int	len_of_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int	ft_lstsize(t_info *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (i);
	while (lst -> next != NULL)
	{
		lst = lst -> next;
		i++;
	}
	return (i + 1);
}

void	ft_close(t_int *digit)
{
	close(digit->curr_pipe[1]);
	if (digit->i > 0)
		close(digit->prev_pipe[0]);
	digit->prev_pipe[0] = digit->curr_pipe[0];
	digit->prev_pipe[1] = digit->curr_pipe[1];
}
