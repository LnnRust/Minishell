/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 04:39:33 by aandreo           #+#    #+#             */
/*   Updated: 2026/03/03 04:44:15 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*init_env_struct(char **envp)
{
	t_env	*head;
	t_env	*tail;
	int		i;

	i = 0;
	head = NULL;
	tail = NULL;
	while (envp[i])
	{
		process_env_entry(envp[i], &head, &tail);
		i++;
	}
	return (head);
}

char	*get_env_value(t_env *env, char *key)
{
	size_t	key_len;

	key_len = ft_strlen(key);
	while (env)
	{
		if (ft_strncmp(env->key, key, key_len) == 0
			&& env->key[key_len] == '\0')
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

static int	update_existing_key(t_env *env, char *key,
				char *value, size_t key_len)
{
	while (env)
	{
		if (ft_strncmp(env->key, key, key_len) == 0
			&& env->key[key_len] == '\0')
		{
			free(env->value);
			if (value)
				env->value = ft_strdup(value);
			else
				env->value = ft_strdup("");
			return (1);
		}
		env = env->next;
	}
	return (0);
}

void	set_env_value(t_env **env, char *key, char *value)
{
	t_env	*new_node;
	size_t	key_len;

	if (!env || !key)
		return ;
	key_len = ft_strlen(key);
	if (update_existing_key(*env, key, value, key_len))
		return ;
	if (value)
		new_node = create_new_node(key, value);
	else
		new_node = create_new_node(key, "");
	if (!new_node)
		return ;
	append_to_end(env, new_node);
}

void	unset_env_value(t_env **env, char *key)
{
	t_env	*current;
	t_env	*prev;
	size_t	key_len;

	if (!env || !*env || !key)
		return ;
	key_len = ft_strlen(key);
	current = *env;
	prev = NULL;
	while (current)
	{
		if (ft_strncmp(current->key, key, key_len) == 0
			&& current->key[key_len] == '\0')
		{
			remove_node(env, prev, current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}
