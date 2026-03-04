/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 21:47:41 by fbenech           #+#    #+#             */
/*   Updated: 2026/03/04 03:37:34 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

int	put_info(t_info *info, t_token *tok, t_built_in built_in)
{
	info->built_in = built_in;
	info->args[info->i++] = ft_strdup(tok->token);
	return (built_in);
}

char	*ft_copy(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	free_envp(t_envp *envp)
{
	free_tab(envp->env);
	free(envp->line);
	free_tab(envp->path);
}

void	free_me(t_envp **ev)
{
	free_token((*ev)->first);
	free_info((*ev)->i_first);
	free_env_list((*ev)->env_list);
	free_tab((*ev)->env);
	free_tab((*ev)->path);
	free((*ev)->line);
	free(*ev);
	*ev = NULL;
}
