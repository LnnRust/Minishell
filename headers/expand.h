/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 20:32:49 by aandreo           #+#    #+#             */
/*   Updated: 2026/03/03 04:49:37 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

void	handle_expand_var(t_expand *ctx);
int		handle_expand(t_expand *ctx);
void	expand(t_token *token, t_env *env, int exit_status);
char	*expand_env_vars(char *str, t_env *env, int exit_status);
void	replace_token(t_token *token, char *tmp);
int		find_expand_len(char *str, t_env *env, int exit_status);
bool	handle_quotes(t_expand *ctx);
char	*extract_var_name(char *str, int start);
char	*itoa(int n);
int		get_int_len(int n);
int		handle_exit_status(int exit_status, int *i);
int		handle_var(char *str, t_env *env, int *i);
int		handle_dollar(char *str, t_env *env, int exit_status, int *i);
void	update_quotes(char c, bool *in_single, bool *in_double);
void	ft_strcpy(char *result, char *str, int *j);
char	*remove_quotes(char *str);
t_env	*init_env_struct(char **envp);
char	*get_env_value(t_env *env, char *key);
void	free_env(t_env *env);
void	set_env_value(t_env **env, char *key, char *value);
void	unset_env_value(t_env **env, char *key);
t_env	*create_new_node(const char *key, const char *value);
void	append_node(t_env **head, t_env **tail, t_env *node);
void	process_env_entry(char *entry, t_env **head, t_env **tail);
void	remove_node(t_env **env, t_env *prev, t_env *current);
void	append_to_end(t_env **env, t_env *new_node);
