/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:49:59 by mehdi             #+#    #+#             */
/*   Updated: 2026/03/04 07:42:37 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	ft_parse_export(char *args)
{
	if (args[0] == '=')
		return (ft_putstr_fd("zsh: bad assignment\n", 2), false);
	if (!ft_isalpha(args[0]))
		return (ft_putstr_fd("zsh: bad assignment\n", 2), false);
	return (true);
}

static void	ft_add_with_value(char *args, t_envp *env)
{
	int		equal;
	int		i;
	char	**key;
	char	*value;

	i = 0;
	value = malloc(sizeof (char) * (ft_strlen(args) + 1));
	if (!value)
		return ;
	key = ft_split(args, '=');
	equal = ft_modiflen(args) + 1;
	while (args[equal])
		value[i++] = args[equal++];
	value[i] = '\0';
	ft_setenv(env, value, key[0]);
	set_env_value(&(env->env_list), key[0], value);
	free_tab(key);
	free(value);
}

static int	check_equal(char *args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (args[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

static void	ft_oneargs(t_envp *c)
{
	char	**tmp;
	int		i;
	int		count;

	count = 0;
	while (c->env[count])
		count++;
	tmp = malloc(sizeof(char *) * (count + 1));
	if (!tmp)
		return ;
	i = 0;
	while (c->env[i])
	{
		tmp[i] = ft_strdup(c->env[i]);
		i++;
	}
	tmp[i] = NULL;
	swap_and_print(tmp);
	free(tmp);
}

bool	builtin_export(t_envp *c, char **args)
{
	int		i;
	int		nb_args;

	i = 1;
	nb_args = ft_nb_args(args);
	if (nb_args == 1)
		return (ft_oneargs(c), true);
	while (args[i])
	{
		if (args[i][0] == '-')
			return (ft_putstr_fd("bash: invalid option\n", 2), false);
		if (ft_parse_export(args[i]))
		{
			if (check_equal(args[i]))
				ft_add_with_value(args[i], c);
			else
				ft_setenv(c, NULL, args[i]);
		}
		i++;
	}
	return (true);
}
