/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:18:26 by memillet          #+#    #+#             */
/*   Updated: 2026/03/03 19:07:38 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_cmd_path(char *cmd, char **path)
{
	char	**split_cmd;
	char	*fullpath;
	char	*tmp;
	int		i;

	i = 0;
	split_cmd = ft_split(cmd, ' ');
	if (!split_cmd || cmd[0] == '\0')
		return (NULL);
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		if (!tmp)
			return (free_tab(split_cmd), NULL);
		fullpath = ft_strjoin(tmp, split_cmd[0]);
		if (!fullpath)
			return (free(tmp), free_tab(split_cmd), NULL);
		if (access(fullpath, X_OK) == 0)
			return (free(tmp), free_tab(split_cmd), fullpath);
		free(tmp);
		free(fullpath);
		i++;
	}
	perror("Error ");
	return (free_tab(split_cmd), NULL);
}

int	handle_heredoc_tok(t_token **token, t_info **info)
{
	if (!(*token)->next)
	{
		ft_putstr_fd("minishell: parse error\n", 2);
		return (0);
	}
	token = &(*token)->next;
	(*info)->args[(*info)->i++] = ft_strdup((*token)->token);
	(*info)->args[(*info)->i++] = NULL;
	(*info)->type = HEREDOC;
	if ((*token)->next)
	{
		(*info)->next = new_info();
		if (!(*info)->next)
			return (0);
		alloc_args((*info)->next, (*token)->next);
		info = &(*info)->next;
	}
	return (1);
}

int	is_delimiter(char *line, char *del)
{
	if (ft_strlen(del) == 0)
		return (ft_strlen(line) == 0);
	return (ft_strncmp(line, del, ft_strlen(del) + 1) == 0);
}

int	has_quoted_delimiter(char *del)
{
	return (del[0] == '\'' || del[0] == '"');
}

char	*strip_quotes(char *del)
{
	int		len;
	char	*clean;

	len = ft_strlen(del);
	if ((del[0] == '\'' && del[len - 1] == '\'')
		|| (del[0] == '"' && del[len - 1] == '"'))
	{
		clean = ft_substr(del, 1, len - 2);
		return (clean);
	}
	return (ft_strdup(del));
}
