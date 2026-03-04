/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:37:38 by mehdi             #+#    #+#             */
/*   Updated: 2026/03/04 01:23:17 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	only_cd(t_envp *c)
{
	char		*pwd;
	char		*target;
	char		*new_pwd;
	struct stat	stabuff;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (1);
	target = ft_getenv("HOME", c);
	if (!target)
		return (ft_putstr_fd("minishell:  cd: HOME not set\n", 2)
			, free(pwd), 1);
	if (chdir(target) == -1)
	{
		if (stat(target, &stabuff))
			return (ft_putstr_fd("minishell: cd: not a directory\n"
					, 2), free(target), free (pwd), 1);
		return (ft_putstr_fd("minishell: cd: no such file or directory\n", 2)
			, free(pwd), 1);
	}
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
		return (ft_putstr_fd("Minishell: cd: no new pwd\n", 2), free(pwd), 1);
	make_setenv(pwd, new_pwd, c);
	return (free(pwd), free(new_pwd), free(target), 0);
}

char	*get_old_pwd(t_envp *c)
{
	char	*oldpwd;

	oldpwd = ft_getenv("OLDPWD", c);
	return (oldpwd);
}

static int	go_back(t_envp *c)
{
	char	*pwd;
	char	*new_pwd;
	char	*old_pwd;
	int		i;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (1);
	old_pwd = get_old_pwd(c);
	if (!old_pwd)
		return (printf("cd: OLDPWD not set\n"), free(pwd), 1);
	i = chdir(old_pwd);
	free(old_pwd);
	if (i == -1)
		return (free(pwd), ft_putstr_fd
			("Minishell: cd: old pwd not set\n", 2), 1);
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
		return (ft_putstr_fd
			("Minishell: cd: Invalid new pwd\n", 2), free(pwd), 1);
	make_setenv(pwd, new_pwd, c);
	printf("%s\n", new_pwd);
	return (free(new_pwd), free(pwd), 0);
}

static int	ft_absolut(char **args, t_envp *c)
{
	char		*pwd;
	char		*new_pwd;
	int			i;
	struct stat	stabuff;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (1);
	i = chdir(args[1]);
	if (i == -1)
	{
		if (stat(args[1], &stabuff) == 0)
			ft_putstr_fd("minishell: cd: not a directory\n", 2);
		else
			ft_putstr_fd("minishell: cd: no such file or directory\n", 2);
		return (free(pwd), 1);
	}
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
		return (ft_putstr_fd("Minishell: cd: Invalid new pwd\n"
				, 2), free(pwd), 1);
	make_setenv(pwd, new_pwd, c);
	free(new_pwd);
	free(pwd);
	return (0);
}

bool	builtin_cd(char **args, t_envp *c)
{
	int		i;

	if (args[1] && args[2])
		return (c->exit_status = 1
			, ft_putstr_fd("minishell: cd: too many arguments\n", 2), false);
	if (args[1] == NULL || ft_strncmp(args[1], "~", 2) == 0)
	{
		i = only_cd(c);
		if (i != 1)
			return (true);
	}
	else if (ft_strncmp(args[1], "-", 2) == 0)
	{
		i = go_back(c);
		if (i != 1)
			return (true);
	}
	else
	{
		i = ft_absolut(args, c);
		if (i != 1)
			return (true);
	}
	return (false);
}
