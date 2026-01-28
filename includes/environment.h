/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:38:34 by ancourti          #+#    #+#             */
/*   Updated: 2026/01/26 13:17:10 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

/// @brief List of environment variables.
typedef struct s_env_lst
{
	char				*env_value;
	struct s_env_lst	*next_env;
}						t_env_lst;

t_env_lst				*env_lstnew(char *value);
// void					env_lstadd_front(t_env_lst **lst, t_env_lst *new);
int						env_lstsize(t_env_lst *lst);
t_env_lst				*env_lstlast(t_env_lst *lst);
void					env_lstadd_back(t_env_lst **lst, t_env_lst *new);
void					envlst_del_one(t_env_lst *stack);
void					envlst_print(t_env_lst **stack);
void					envlst_clear(t_env_lst **stack);
t_env_lst				*init_env_lst(void);
char					**env_lst_to_str_array(t_env_lst *lst);

#endif
