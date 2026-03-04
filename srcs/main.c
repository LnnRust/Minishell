/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 22:27:31 by aandreo           #+#    #+#             */
/*   Updated: 2026/03/04 07:42:32 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*read_line_non_interactive(void)
{
	char	*line;
	char	*new_line;
	char	c;
	ssize_t	ret;
	int		len;

	line = ft_strdup("");
	if (!line)
		return (NULL);
	len = 0;
	ret = read(STDIN_FILENO, &c, 1);
	while (ret > 0)
	{
		if (c == '\n')
			break ;
		new_line = malloc(sizeof(char) * (len + 2));
		if (!new_line)
			return (free(line), NULL);
		ft_memcpy(new_line, line, len);
		new_line[len++] = c;
		new_line[len] = '\0';
		free(line);
		line = new_line;
		ret = read(STDIN_FILENO, &c, 1);
	}
	if (ret <= 0 && len == 0)
		return (free(line), NULL);
	return (line);
}

int	set_up_and_init(t_envp **envp, t_shell **shell, char **ev)
{
	*envp = new_envp(ev);
	if (!*envp)
		return (1);
	*shell = new_shell();
	if (!*shell)
	{
		free(*envp);
		return (1);
	}
	setup_parent_signals();
	return (0);
}

static void	parse_tokens(t_envp *envp, t_info **info, t_count *count)
{
	t_token	*token;
	t_info	*cur;

	cur = *info;
	token = envp->first;
	alloc_args(cur, token);
	while (token)
	{
		if (!big_loop(&token, count, envp, &cur))
			break ;
		if (token)
			token = token->next;
	}
	cur->args[cur->i] = NULL;
}

static int	handle_readline(t_envp *envp, t_count *count)
{
	if (isatty(STDIN_FILENO))
		envp->line = readline("minishell> ");
	else
		envp->line = read_line_non_interactive();
	if (!envp->line)
	{
		if (isatty(STDIN_FILENO))
			ft_putstr_fd("successfully exited minishell !\n", 1);
		free(count);
		return (0);
	}
	if (*envp->line)
		add_history(envp->line);
	return (1);
}

static void	do_loop(t_envp *envp, t_shell *shell, t_count *count)
{
	while (1)
	{
		count = new_count();
		if (!handle_readline(envp, count))
			break ;
		if (!handle_syntax(envp, count))
			continue ;
		envp->i_first = new_info();
		parse_tokens(envp, &envp->i_first, count);
		free(count);
		shell->exit_status = envp->exit_status;
		ft_exec(envp->i_first, envp, shell);
		envp->exit_status = shell->exit_status;
		free_loop_data(envp);
	}
}

int	main(int ac, char **av, char **ev)
{
	t_envp	*envp;
	t_count	*count;
	t_shell	*shell;

	(void)ac;
	(void)av;
	envp = NULL;
	shell = NULL;
	count = NULL;
	if (set_up_and_init(&envp, &shell, ev))
		return (1);
	do_loop(envp, shell, count);
	free_envp(envp);
	free_env_list(envp->env_list);
	free(envp);
	free(shell);
	return (0);
}
