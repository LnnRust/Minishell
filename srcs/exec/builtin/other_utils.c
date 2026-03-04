/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 04:15:23 by fbenech           #+#    #+#             */
/*   Updated: 2026/03/04 02:27:43 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*create_entry(char *key, char *value)
{
	char	*entry;
	char	*tmp;

	if (value)
		entry = ft_strjoin(key, "=");
	else
		entry = ft_strjoin(key, "\0");
	if (!entry)
		return (NULL);
	if (value)
	{
		tmp = ft_strjoin(entry, value);
		free(entry);
		return (tmp);
	}
	return (entry);
}

int	replace_env_var(t_envp *c, char *key, char *entry)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(key);
	while (c->env[i])
	{
		if (ft_strncmp(c->env[i], key, len) == 0
			&& (c->env[i][len] == '=' || c->env[i][len] == '\0'))
		{
			free(c->env[i]);
			c->env[i] = ft_strdup(entry);
			return (1);
		}
		i++;
	}
	return (0);
}

void	pipe_builtin(t_info *info, t_int *digit, t_envp *ev, t_shell *status)
{
	if (digit->fd_inf != STDIN_FILENO)
		dup2(digit->fd_inf, STDIN_FILENO);
	if (digit->fd_outf != STDOUT_FILENO)
		dup2(digit->fd_outf, STDOUT_FILENO);
	ft_built_in(info, ev, status);
}

void	ft_error(t_int *digit, t_info *info, t_shell *status)
{
	if (digit->fd_inf < 0)
	{
		status->exit_status = 130;
		dup2(digit->save_in, STDIN_FILENO);
		dup2(digit->save_out, STDOUT_FILENO);
		close(digit->save_in);
		close(digit->save_out);
		return ;
	}
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(info->args[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	status->exit_status = 126;
}
