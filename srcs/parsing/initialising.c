/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialising.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 03:37:15 by fbenech           #+#    #+#             */
/*   Updated: 2026/03/03 13:03:34 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_info	*new_info(void)
{
	t_info	*info;

	info = ft_calloc(1, sizeof(t_info));
	if (!info)
		return (NULL);
	info->i = 0;
	info->argc = 0;
	info->args = NULL;
	info->cmd_pth = NULL;
	info->built_in = -1;
	info->built_out = 0;
	info->first_redirs = NULL;
	info->type = 0;
	info->next = NULL;
	return (info);
}

t_count	*new_count(void)
{
	t_count	*count;

	count = ft_calloc(1, sizeof(t_count));
	if (!count)
		return (NULL);
	count->braquet = 0;
	count->dquotes = 0;
	count->embrace = 0;
	count->i = 0;
	count->square_brqt = 0;
	count->squotes = 0;
	return (count);
}

t_envp	*new_envp(char **env)
{
	int		i;
	t_envp	*envp;

	envp = ft_calloc(1, sizeof(t_envp));
	if (!envp)
		return (NULL);
	i = 0;
	while (env[i])
		i++;
	envp->env = malloc(sizeof(char *) * (i + 1));
	if (!envp->env)
		return (free(envp), NULL);
	i = 0;
	while (env[i])
	{
		envp->env[i] = ft_strdup(env[i]);
		i++;
	}
	envp->env[i] = NULL;
	envp->env_list = init_env_struct(envp->env);
	envp->exit_status = 0;
	envp->first = NULL;
	envp->line = NULL;
	envp->path = get_all_path(envp->env);
	return (envp);
}

t_int	*new_digit(void)
{
	t_int	*digit;

	digit = ft_calloc(1, sizeof(t_int));
	if (!digit)
		return (NULL);
	digit->nb_cmd = 0;
	digit->curr_pipe[0] = -1;
	digit->curr_pipe[1] = -1;
	digit->prev_pipe[0] = -1;
	digit->prev_pipe[1] = -1;
	digit->fd_inf = STDIN_FILENO;
	digit->fd_outf = STDOUT_FILENO;
	digit->pid = 0;
	digit->pids = NULL;
	digit->last_status = 0;
	return (digit);
}

t_shell	*new_shell(void)
{
	t_shell	*shell;

	shell = ft_calloc(1, sizeof(t_shell));
	if (!shell)
		return (NULL);
	shell->exit_status = 0;
	shell->running = true;
	shell->env = NULL;
	return (shell);
}
