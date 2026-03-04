/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 04:43:07 by aandreo           #+#    #+#             */
/*   Updated: 2026/03/03 04:44:47 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_env	*create_new_node(const char *key, const char *value)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

void	append_node(t_env **head, t_env **tail, t_env *node)
{
	if (!*head)
	{
		*head = node;
		*tail = node;
	}
	else
	{
		(*tail)->next = node;
		*tail = node;
	}
}

void	process_env_entry(char *entry, t_env **head, t_env **tail)
{
	t_env	*node;
	char	*equal;
	char	*key;

	equal = ft_strchr(entry, '=');
	if (!equal)
		return ;
	key = ft_substr(entry, 0, equal - entry);
	node = create_new_node(key, equal + 1);
	free(key);
	append_node(head, tail, node);
}

void	remove_node(t_env **env, t_env *prev, t_env *current)
{
	if (prev)
		prev->next = current->next;
	else
		*env = current->next;
	free(current->key);
	free(current->value);
	free(current);
}

void	append_to_end(t_env **env, t_env *new_node)
{
	t_env	*current;

	if (!*env)
	{
		*env = new_node;
		return ;
	}
	current = *env;
	while (current->next)
		current = current->next;
	current->next = new_node;
}
