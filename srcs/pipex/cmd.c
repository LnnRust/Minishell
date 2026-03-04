/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:48:14 by memillet          #+#    #+#             */
/*   Updated: 2026/01/23 17:07:09 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_cmd(t_char *cmd, t_int *digit, char **av)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (i < digit->ac)
	{
		cmd->all_cmd[j] = malloc(sizeof(char) * (ft_strlen(av[i]) + 1));
		if (!cmd->all_cmd[j])
			return ;
		ft_strlcpy(cmd->all_cmd[j], av[i], (ft_strlen(av[i]) + 1));
		i++;
		j++;
	}
	cmd->all_cmd[j] = NULL;
}

char	*cmd_path(char *cmd, char **path)
{
	int		i;
	char	*newpth;

	i = 0;
	while (path[i])
	{
		newpth = get_full_path(path[i], cmd);
		if (access(newpth, X_OK) == 0)
			return (newpth);
		else
			free (newpth);
		i++;
	}
	print_error("Invalid command !");
	return (NULL);
}

char	**get_all_path(char **envp)
{
	char	*tmp;
	char	**path;
	int		i;

	i = -1;
	tmp = NULL;
	if (!envp[0])
		return (NULL);
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			tmp = envp[i] + 5;
			break ;
		}
	}
	if (!tmp)
		return (NULL);
	path = ft_split(tmp, ':');
	if (!path)
	{
		perror("Error ");
		return (NULL);
	}
	return (path);
}

char	*split_cmd(char *cmd)
{
	char	**tab;
	char	*result;
	int		i;

	i = 1;
	if (!cmd)
		return (NULL);
	tab = ft_split(cmd, ' ');
	if (!tab)
		return (NULL);
	result = tab[0];
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (result);
}
