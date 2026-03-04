/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:46:03 by fbenech           #+#    #+#             */
/*   Updated: 2026/03/04 00:25:14 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "minishell.h"
#include <aio.h>
#include <stdbool.h>

bool	builtin_cd(char **args, t_envp *c);
char	*get_old_pwd(t_envp *c);
void	make_setenv(char *pwd, char *new_pwd, t_envp *c);
char	*ft_getenv(char *key, t_envp *c);
bool	builtin_echo(char **cmd);
bool	builtin_env(t_envp *c);
int		ft_nb_args(char **cmd);
bool	builtin_exit(char **cmd, int g_status, t_envp *envp, t_shell *status);
bool	builtin_pwd(void);
bool	builtin_unset(t_envp *c, char **target);
bool	builtin_export(t_envp *c, char **args);
char	*ft_strcpytoi(char *dest, char *src, int i);
int		ft_modiflen(char *str);
char	*create_entry(char *key, char *value);
char	**ft_setenv(t_envp *c, char *value, char *key);
int		replace_env_var(t_envp *c, char *key, char *entry);

char	*cmd_path(char *cmd, char **path);
char	*get_full_path(char *path, char *cmd);
char	**get_all_path(char **envp);

//built_out.c

void	parent(t_int *digit, int i);
void	pipe_builtin(t_info *info, t_int *digit, t_envp *ev, t_shell *status);
void	ft_built_out(t_info *info, t_int *digit, t_envp *envp, t_shell *stats);
int		print_error(char *msg);

//child.c

void	choose_child(t_info *info, t_envp *ev, t_int *digit, t_shell *status);
int		middle_cmd(t_info *info, t_envp *ev, t_int *digit, t_shell *status);
int		last_cmd(t_info *info, t_envp *ev, t_int *digit, t_shell *status);
int		first_cmd(t_info *info, t_envp *ev, t_int *digit, t_shell *status);
int		one_cmd(t_info *info, t_envp *ev, t_int *digit, t_shell *status);

//exec.c

void	ft_exec(t_info *info, t_envp *ev, t_shell *status);
void	ft_built_in(t_info *info, t_envp *ev, t_shell *status);
void	ft_fd(t_rd *redir, t_int *digit, t_envp *envp, t_shell *st);

//heredoc.c

int		heredoc(char *delimeter, t_envp *envp, t_int *digit, t_shell *st);
int		len_of_tab(char **str);
int		ft_lstsize(t_info *lst);
void	ft_help_fd(t_int *digit);
void	ft_do_exec(t_int *dgt, t_envp *ev, t_shell *tus);
void	ft_start(t_info *info, t_int *digit, t_envp *ev, t_shell *status);
void	ft_error(t_int *digit, t_info *info, t_shell *status);
void	ft_close(t_int *digit);
void	swap_and_print(char **tmp);
int		handle_heredoc_tok(t_token **token, t_info **info);
void	setup_heredoc(char *del, char **clean, int *expand);
int		make_fd_read(int status);
char	*expand_heredoc(char *str, t_env *env, t_envp *envp);
int		is_delimiter(char *line, char *del);
int		has_quoted_delimiter(char *del);
char	*strip_quotes(char *del);
void	ft_close_call(t_int *digit);
void	if_signals(int fd, char *tmp, char *clean_del);
