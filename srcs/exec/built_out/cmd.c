/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:23:08 by memillet          #+#    #+#             */
/*   Updated: 2026/03/02 15:19:42 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cmd_path(char *cmd, char **path)
{
	int		i;
	char	*newpth;

	if (!cmd)
		return (NULL);
	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	if (!path)
		return (NULL);
	i = 0;
	while (path[i])
	{
		newpth = get_full_path(path[i], cmd);
		if (newpth && access(newpth, X_OK) == 0)
			return (newpth);
		if (newpth)
			free (newpth);
		i++;
	}
	return (NULL);
}

char	*get_full_path(char *path, char *cmd)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	if (!path)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(cmd) + 2));
	if (!dest)
		return (NULL);
	while (path[i])
	{
		dest[i] = path[i];
		i++;
	}
	dest[i++] = '/';
	while (cmd[j])
	{
		dest[i] = cmd[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
