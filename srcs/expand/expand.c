/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 23:17:25 by aandreo           #+#    #+#             */
/*   Updated: 2026/02/18 01:31:17 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static void	ft_strcpy(char *result, char *str_to_copy, int *j)
{
	int i;

	i = 0;
	while(str_to_copy[i])
	{
		result[*j] = str_to_copy[i];
		(*j)++;
		i++;
	}
}

static char *itoa(int n)
{
	char *str;
	int len;
	int tmp;
	
	if (n == 0)
		len = 1;
	else
	{
		len = 0;
		tmp = n;
		while (tmp > 0)
		{
			len++;
			tmp /= 10;
		}
	}
	str = malloc(len + 1);
	if (!str)
		return NULL;
	str[len] = '\0';
	if (n == 0)
		return (str[0] = '0', str);
	while (n > 0)
	{
		len--;
		str[len] = '0' + (n % 10); 
		n /= 10; 
	}
	return (str);
}

//return var name from the string
char	*extract_var_name(char *str, int start)
{
	int i;
	int len;
	int total;
	char *var_name;

	i = start;
	len = 0;
	while(str[i])
	{
		if(!isalpha(str[i]) || str[i] == '_') //if not valid var char
			return NULL;
		else
		{
			len++;
			i++;
		}
	}
	var_name = malloc(len + 1);
	if(!var_name)
		return (NULL);
	total = start + len;
	i = 0;
	while(start < total)
	{
		var_name[i] = str[start];
		i++;
		start++;
	}
	var_name[len] = '\0';
	return (var_name);
}

// handle case $? and $VAR
//TODO need to add exit status management
//TODO finish this function and rethink how to norm it
//TODO 
int handle_expand(int *i, int *j, t_env *env, char *str, char *result, int exit_status)
{
	char *num_str;
	char *var_name;
	char *value;
	size_t var_len;
	// case $?
	if(str[*i + 1] == '?')
	{
		num_str = itoa(exit_status);
		ft_strcpy(result, num_str, j);
		free(num_str);
		*i += 2;
		return (0);
	}
	else
	{
		var_name = extract_var_name(str, *i + 1);
		if(var_name == NULL)
		{
			result[*j] = str[*i];
			(*i)++;
			(*j)++;
			return (0);
		}
		value = get_env_value(env, var_name);
		if(value)
			ft_strcpy(result, value, j);
		var_len = ft_strlen(var_name);
		*i += var_len + 1;
		free(var_name);
		return (0);
	}
}

// return the final string with the var expanded 
// needs to get split into few functions for norm
char	*expand_env_vars(char *str, t_env *env, int exit_status)
{
	int i;
	int j;
	int len;
	char *result;
	bool in_double;
	bool in_single;

	len = find_expand_len(str, env,  exit_status);
	in_double = false;
	in_single = false;
	result = malloc(len  + 1);
	if(!result)
		return (NULL);
	i = 0;
	j = 0;
	while(str[i])
	{
		if(str[i] == '\'' && !in_double)
		{
			in_single = !in_single;
			result[j++] = str[i++];
			continue;
		}
		if(str[i] == '"' && !in_single)
		{
			in_double = !in_double;
			result[j++] = str[i++];
			continue;
		}
		if(str[i] == '$' && !in_single && str[i + 1])
		{
			handle_expand(&i, &j, env, str, result, exit_status);
			continue;
		}
		i++;
	}
	result[j] = '\0';
	return (result);
}

// return len of string that gets expanded to malloc good size
int find_expand_len(char *str, t_env *env, int exit_status)
{
	int length;
	int i;
	bool in_single;
	bool in_double;

	length = 0;
	i = 0;
	in_single = false;
	in_double = false;
	while(str[i])
	{
		if(str[i] == '\'' && !in_double)
		{
			in_double = !in_double;
			
		}
	}
}