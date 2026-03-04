/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 03:57:12 by aandreo           #+#    #+#             */
/*   Updated: 2026/03/03 04:40:12 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	get_int_len(int n)
{
	int	len;
	int	tmp;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		tmp = -n;
	else
		tmp = n;
	while (tmp > 0)
	{
		len++;
		tmp /= 10;
	}
	return (len);
}

int	handle_exit_status(int exit_status, int *i)
{
	*i += 2;
	if (exit_status == 0)
		return (1);
	return (3);
}

int	handle_var(char *str, t_env *env, int *i)
{
	char	*var_name;
	char	*value;
	int		len;

	len = 0;
	var_name = extract_var_name(str, *i + 1);
	if (var_name)
	{
		value = get_env_value(env, var_name);
		if (value)
			len += ft_strlen(value);
		*i += ft_strlen(var_name) + 1;
		free(var_name);
	}
	else
	{
		(*i)++;
		len = 1;
	}
	return (len);
}

int	handle_dollar(char *str, t_env *env, int exit_status, int *i)
{
	if (!str[*i + 1])
	{
		(*i)++;
		return (1);
	}
	if (str[*i + 1] == '?')
		return (handle_exit_status(exit_status, i));
	return (handle_var(str, env, i));
}

void	update_quotes(char c, bool *in_single, bool *in_double)
{
	if (c == '\'' && !(*in_double))
		*in_single = !(*in_single);
	else if (c == '"' && !(*in_single))
		*in_double = !(*in_double);
}
