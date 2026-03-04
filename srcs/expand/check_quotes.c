/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 23:17:27 by aandreo           #+#    #+#             */
/*   Updated: 2026/03/03 04:44:23 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_first_quotes(char *prompt)
{
	int	i;

	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == '"' || prompt[i] == '\'')
		{
			if (prompt[i] == '"')
				return (true);
			return (false);
		}
		i++;
	}
	return (false);
}

// return good size to malloc -> without delimitor quotes
static int	count_without_quotes(char *str)
{
	int	i;
	int	len;
	int	in_single;
	int	in_double;

	i = 0;
	len = 0;
	in_single = 0;
	in_double = 0;
	while (str[i])
	{
		if (str[i] == '"' && !in_single)
			in_double = !in_double;
		else if (str[i] == '\'' && !in_double)
			in_single = !in_single;
		else
			len++;
		i++;
	}
	return (len);
}

// only remove delimitor quotes
// "'wadwad'" == 'wadwad'
char	*remove_quotes(char *str)
{
	int		i;
	int		j;
	int		in_single;
	int		in_double;
	char	*result;

	result = malloc(count_without_quotes(str) + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	in_single = 0;
	in_double = 0;
	while (str[i])
	{
		if (str[i] == '"' && !in_single)
			in_double = !in_double;
		else if (str[i] == '\'' && !in_double)
			in_single = !in_single;
		else
			result[j++] = str[i];
		i++;
	}
	result[j] = '\0';
	return (result);
}

void	ft_strcpy(char *result, char *str, int *j)
{
	int	i;

	i = 0;
	while (str[i])
	{
		result[*j] = str[i];
		(*j)++;
		i++;
	}
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		free(env->key);
		free(env->value);
		free(env);
		env = tmp;
	}
}
