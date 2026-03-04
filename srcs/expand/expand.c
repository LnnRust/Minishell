/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 03:49:45 by aandreo           #+#    #+#             */
/*   Updated: 2026/03/03 04:35:38 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_expand_var(t_expand *ctx)
{
	char	*var_name;
	char	*value;
	size_t	var_len;

	var_name = extract_var_name(ctx->str, ctx->i + 1);
	if (var_name == NULL)
	{
		ctx->result[ctx->j++] = ctx->str[ctx->i++];
		return ;
	}
	value = get_env_value(ctx->env, var_name);
	if (value)
		ft_strcpy(ctx->result, value, &ctx->j);
	var_len = ft_strlen(var_name);
	ctx->i += var_len + 1;
	free(var_name);
}

int	handle_expand(t_expand *ctx)
{
	char	*num_str;

	if (ctx->str[ctx->i + 1] == '?')
	{
		num_str = itoa(ctx->exit_status);
		ft_strcpy(ctx->result, num_str, &ctx->j);
		free(num_str);
		ctx->i += 2;
		return (0);
	}
	handle_expand_var(ctx);
	return (0);
}

static void	expand_loop(t_expand *ctx)
{
	ctx->i = 0;
	ctx->j = 0;
	ctx->in_double = false;
	ctx->in_single = false;
	while (ctx->str[ctx->i])
	{
		if (handle_quotes(ctx))
			continue ;
		if (ctx->str[ctx->i] == '$' && !ctx->in_single
			&& ctx->str[ctx->i + 1])
		{
			handle_expand(ctx);
			continue ;
		}
		ctx->result[ctx->j++] = ctx->str[ctx->i++];
	}
	ctx->result[ctx->j] = '\0';
}

char	*expand_env_vars(char *str, t_env *env, int exit_status)
{
	t_expand	ctx;
	int			len;

	len = find_expand_len(str, env, exit_status);
	ctx.result = malloc(len + 1);
	if (!ctx.result)
		return (NULL);
	ctx.str = str;
	ctx.env = env;
	ctx.exit_status = exit_status;
	expand_loop(&ctx);
	return (ctx.result);
}

void	expand(t_token *token, t_env *env, int exit_status)
{
	char	*tmp;
	int		has_quotes;

	if (!token || !token->token)
		return ;
	has_quotes = ft_strchr(token->token, '\'')
		|| ft_strchr(token->token, '"');
	if (ft_strchr(token->token, '$'))
	{
		tmp = expand_env_vars(token->token, env, exit_status);
		if (!tmp)
			return ;
		replace_token(token, tmp);
	}
	if (has_quotes)
	{
		tmp = remove_quotes(token->token);
		if (!tmp)
			return ;
		replace_token(token, tmp);
	}
}
