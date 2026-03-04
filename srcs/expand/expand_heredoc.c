/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 08:04:54 by fbenech           #+#    #+#             */
/*   Updated: 2026/03/03 17:31:44 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_heredoc(char *str, t_env *env, t_envp *envp)
{
	char	*tmp;
	int		has_quotes;

	if (!str)
		return (NULL);
	tmp = NULL;
	has_quotes = ft_strchr(str, '\'') || ft_strchr(str, '"');
	if (ft_strchr(str, '$'))
	{
		tmp = expand_env_vars(str, env, envp->exit_status);
		if (!tmp)
			return (NULL);
	}
	if (has_quotes)
	{
		if (tmp)
		{
			str = tmp;
			tmp = remove_quotes(str);
			free(str);
		}
		else
			tmp = remove_quotes(str);
	}
	return (tmp);
}
