/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 20:33:01 by aandreo           #+#    #+#             */
/*   Updated: 2026/03/04 03:36:43 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// command
int				check_basic_command(t_token *tok, t_info *info);
int				check_e_command(t_info *info, t_token *token);
int				is_token_cmd(t_envp *env, t_token *token, t_info *info);
int				check_if_built_out(char *cmd, t_envp *envp);

// utils

int				put_info(t_info *info, t_token *tok, t_built_in built_in);
char			*ft_copy(char *src);
int				is_sep(char c, char *sep);
int				big_loop(t_token **token, t_count *count,
					t_envp *envp, t_info **info);

// parsing

int				check_syntaxe(t_envp *envp);
int				handle_syntax(t_envp *envp, t_count *count);
int				is_right_n_operator(t_token *token, t_count *count);

//	token

t_token			*tokenizer(char *input);
t_token			*create_token(char *value, int type);
t_token_type	get_type(char *token, int has_quotes);
void			token_addback(t_token **token, t_token *new_token);
void			free_tokens(t_token *head);
void			print_tokens(t_token *head);
int				is_space(char c);
int				is_separator(char c, int in_single, int in_double);
int				handle_quote_toggle(char c, int *in_single, int *in_double);
int				create_and_add(t_token **tokens, char *token, int has_quotes);

// is_operator

int				is_space(char c);
int				is_dollar_sign(char c);
int				is_simple_quote(char c);
int				is_rd_out(char *c, int i);
int				is_overwrite(char *c, int i);
int				is_rd_in(char *c, int i);
int				is_open_bracket(char c);
int				is_close_bracket(char c);
int				is_double_quotes(char c);
int				is_double_ampersand(char *c, int i);
int				is_pipe(char c);
int				is_double_pipe(char *c, int i);
int				is_heredoc(char *c, int i);
int				is_subshell(char *c);
int				is_close_s_braquet(char c);
int				is_open_s_bracket(char c);
int				is_slash(char c);
int				is_close_embrace(char c);
int				is_open_embrace(char c);
int				is_wildcards(char c);
int				is_equal(char c);

// redirection

int				redirection(t_token *token, t_info *info);
t_rd			*last_rd(t_rd *rd);
void			add_rd_back(t_rd **rd, t_rd *new);
void			new_rd_lst(t_rd **first_rd, char *file, t_rd_type type);
int				big_loop(t_token **token, t_count *count,
					t_envp *envp, t_info **info);
// initialising

t_info			*new_info(void);
t_count			*new_count(void);
t_envp			*new_envp(char **env);
t_int			*new_digit(void);
t_shell			*new_shell(void);

// handle args

int				alloc_args(t_info *info, t_token *token);
void			count_args(t_token *token, t_info *info);

// free_all
void			free_env(t_env *env);
void			free_envp(t_envp *envp);
void			free_env_list(t_env *env);
void			free_info(t_info *info);
void			free_token(t_token *token);
void			free_child(t_envp *ev, t_int *digit, t_shell *status);
void			free_me(t_envp **ev);

// utils of main
void			free_loop_data(t_envp *envp);