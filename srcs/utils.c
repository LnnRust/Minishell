/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:38:59 by memillet          #+#    #+#             */
/*   Updated: 2026/03/03 19:42:45 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_loop_data(t_envp *envp)
{
	free_token(envp->first);
	envp->first = NULL;
	free_info(envp->i_first);
	free(envp->line);
	envp->line = NULL;
}
