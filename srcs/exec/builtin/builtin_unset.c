/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:50:04 by mehdi             #+#    #+#             */
/*   Updated: 2026/03/04 00:15:26 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	for_path(t_envp *c, char *target)
{
	if (ft_strncmp(target, "PATH", 5) == 0)
	{
		free_tab(c->path);
		c->path = NULL;
	}
}

static int	env_key_match(const char *entry, const char *key)
{
	size_t	klen;

	if (!entry || !key)
		return (0);
	klen = ft_strlen(key);
	if (ft_strncmp(entry, key, klen) != 0)
		return (0);
	return ((entry[klen] == '=') || (entry[klen] == '\0'));
}

bool	builtin_unset(t_envp *c, char **target)
{
	int	i;
	int	j;

	if (!c || !target)
		return (false);
	j = 0;
	while (target[j])
	{
		i = 0;
		while (c->env[i] && !env_key_match(c->env[i], target[j]))
			i++;
		if (c->env[i])
		{
			free(c->env[i]);
			while (c->env[i])
			{
				c->env[i] = c->env[i + 1];
				i++;
			}
			unset_env_value(&(c->env_list), target[j]);
			for_path(c, target[j]);
		}
		j++;
	}
	return (true);
}
