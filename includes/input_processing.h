/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:19:35 by ancourti          #+#    #+#             */
/*   Updated: 2026/01/30 20:04:30 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_PROCESSING_H
# define INPUT_PROCESSING_H

# include "Minishell.h"

void		process_input(t_minishell_data *data);
t_token_lst	*token_lst_new(char *value);
void		token_lst_add_back(t_token_lst **stack, t_token_lst *new);
void		token_lst_del_one(t_token_lst *stack);
void		token_lst_clear(t_token_lst **stack);
void		token_lst_print(t_token_lst **stack);
void		create_token_lst(t_minishell_data *data);
t_token_lst	*token_lst_last(t_token_lst *stack);

#endif
