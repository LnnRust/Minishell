/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:04:39 by memillet          #+#    #+#             */
/*   Updated: 2026/03/03 04:26:23 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strcpytoi(char *dest, char *src, int i)
{
	int	j;

	j = 0;
	while (j < i && src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int	ft_modiflen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (i);
}

char	**ft_setenv(t_envp *c, char *value, char *key)
{
	char	**new_env;
	char	*entry;
	int		i;

	entry = create_entry(key, value);
	if (!entry)
		return (NULL);
	if (replace_env_var(c, key, entry))
		return (free(entry), c->env);
	new_env = malloc(sizeof(char *) * (len_tab(c->env) + 2));
	if (!new_env)
		return (free(entry), NULL);
	i = -1;
	while (c->env[++i])
		new_env[i] = ft_strdup(c->env[i]);
	new_env[i++] = ft_strdup(entry);
	new_env[i] = NULL;
	free(entry);
	free_tab(c->env);
	return (c->env = new_env);
}

void	make_setenv(char *pwd, char *new_pwd, t_envp *c)
{
	ft_setenv(c, pwd, "OLDPWD");
	ft_setenv(c, new_pwd, "PWD");
	set_env_value(&(c->env_list), "OLDPWD", pwd);
	set_env_value(&(c->env_list), "PWD", new_pwd);
}

char	*ft_getenv(char *key, t_envp *c)
{
	char	*value;
	char	*env_value;
	int		size;

	env_value = get_env_value(c->env_list, key);
	if (!env_value)
		return (NULL);
	size = ft_strlen(env_value);
	value = malloc(sizeof(char) * (size + 1));
	if (!value)
		return (NULL);
	ft_strlcpy(value, env_value, size + 1);
	return (value);
}
