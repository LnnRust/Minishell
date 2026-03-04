/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:58:48 by fbenech           #+#    #+#             */
/*   Updated: 2026/03/03 10:24:49 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_basic_command(t_token *tok, t_info *info)
{
	if (tok->token[0] == 'e')
		return (check_e_command(info, tok));
	else if (ft_strncmp(tok->token, "cd", 3) == 0)
		return (put_info(info, tok, CD));
	else if (ft_strncmp(tok->token, "pwd", 4) == 0)
		return (put_info(info, tok, PWD));
	else if (ft_strncmp(tok->token, "unset", 6) == 0)
		return (put_info(info, tok, UNSET));
	return (0);
}

int	check_e_command(t_info *info, t_token *token)
{
	if (ft_strncmp(token->token, "env", 4) == 0)
		return (put_info(info, token, ENV));
	else if (ft_strncmp(token->token, "export", 7) == 0)
		return (put_info(info, token, EXPORT));
	else if (ft_strncmp(token->token, "echo", 5) == 0)
	{
		put_info(info, token, ECHO);
		if (token->next && ft_strncmp(token->next->token, "-n", 3) == 0)
		{
			token = token->next;
			put_info(info, token, ECHO);
		}
		return (ECHO);
	}
	else if (ft_strncmp(token->token, "exit", 5) == 0)
		return (put_info(info, token, EXIT));
	return (0);
}

int	is_token_cmd(t_envp *env, t_token *token, t_info *info)
{
	if (check_basic_command(token, info) != 0)
		return (1);
	else if (info->built_in == -1 && check_if_built_out(token->token, env))
	{
		info->built_out = 1;
		info->args[info->i++] = ft_strdup(token->token);
		return (1);
	}
	else if (!info->built_in)
		info->built_in = -1;
	return (0);
}

int	check_if_built_out(char *cmd, t_envp *env)
{
	char	*path;

	path = cmd_path(cmd, env->path);
	if (path != NULL)
	{
		free(path);
		return (1);
	}
	return (0);
}
