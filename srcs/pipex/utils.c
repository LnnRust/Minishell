/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:43:49 by memillet          #+#    #+#             */
/*   Updated: 2026/02/26 01:42:40 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	print_error(char *msg)
{
	printf("%s\n", msg);
	exit(0);
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

void	free_tab(char **s)
{
	int	j;

	j = 0;
	if (!s)
		return ;
	while (s[j])
		free(s[j++]);
	free(s);
}

void	malloc_struct(t_char *cmd, t_int *digit)
{
	cmd->all_cmd = malloc(sizeof(char *) * (digit->nbcmd + 2));
	if (!cmd->all_cmd)
		return ;
	cmd->cmdb = malloc(sizeof(char *) * (digit->nbcmd + 1));
	if (!cmd->cmdb)
		return (free_tab(cmd->all_cmd));
	cmd->cmdpth = malloc(sizeof(char *) * (digit->nbcmd + 1));
	if (!cmd->cmdpth)
		return (free_tab(cmd->all_cmd), free_tab(cmd->cmdb));
	cmd->args = malloc(sizeof(char **) * (digit->nbcmd));
	if (!cmd->args)
	{
		free_tab(cmd->all_cmd);
		return (free_tab(cmd->cmdb), free_tab(cmd->cmdpth));
	}
}

void	clear_master(t_char *cmd, t_int *digit)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < digit->nbcmd)
	{
		if (cmd->args[i])
		{
			j = 0;
			while (cmd->args[i][j])
			{
				free(cmd->args[i][j]);
				j++;
			}
			free(cmd->args[i]);
		}
		i++;
	}
	free(cmd->args);
	free_tab(cmd->path);
	free_tab(cmd->cmdpth);
	free_tab(cmd->cmdb);
	free(cmd);
	free(digit);
}
