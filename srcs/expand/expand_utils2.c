/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 04:21:26 by aandreo           #+#    #+#             */
/*   Updated: 2026/03/03 04:23:51 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	replace_token(t_token *token, char *tmp)
{
	char	*old;

	old = token->token;
	token->token = tmp;
	free(old);
}

int	find_expand_len(char *str, t_env *env, int exit_status)
{
	int		i;
	int		len;
	bool	in_single;
	bool	in_double;

	i = 0;
	len = 0;
	in_single = false;
	in_double = false;
	while (str[i])
	{
		update_quotes(str[i], &in_single, &in_double);
		if (str[i] == '$' && !in_single)
		{
			len += handle_dollar(str, env, exit_status, &i);
			continue ;
		}
		len++;
		i++;
	}
	return (len + 100);
}

bool	handle_quotes(t_expand *ctx)
{
	if (ctx->str[ctx->i] == '\'' && !ctx->in_double)
	{
		ctx->in_single = !ctx->in_single;
		ctx->result[ctx->j++] = ctx->str[ctx->i++];
		return (true);
	}
	if (ctx->str[ctx->i] == '"' && !ctx->in_single)
	{
		ctx->in_double = !ctx->in_double;
		ctx->result[ctx->j++] = ctx->str[ctx->i++];
		return (true);
	}
	return (false);
}

char	*itoa(int n)
{
	char	*str;
	int		len;
	int		tmp;
	int		is_neg;

	is_neg = (n < 0);
	len = get_int_len(n);
	str = malloc(len + is_neg + 1);
	if (!str)
		return (NULL);
	str[len + is_neg] = '\0';
	if (is_neg)
		str[0] = '-';
	if (n == 0)
		return (str[0] = '0', str);
	if (n < 0)
		tmp = -n;
	else
		tmp = n;
	while (tmp > 0)
	{
		str[--len + is_neg] = '0' + (tmp % 10);
		tmp /= 10;
	}
	return (str);
}

char	*extract_var_name(char *str, int start)
{
	int		i;
	int		len;
	int		total;
	char	*var_name;

	i = start;
	len = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			break ;
		len++;
		i++;
	}
	if (len == 0)
		return (NULL);
	var_name = malloc(len + 1);
	if (!var_name)
		return (NULL);
	total = start + len;
	i = 0;
	while (start < total)
		var_name[i++] = str[start++];
	var_name[len] = '\0';
	return (var_name);
}
