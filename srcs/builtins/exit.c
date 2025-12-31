/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:44:13 by aandreo           #+#    #+#             */
/*   Updated: 2025/12/31 18:45:16 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Minishell.h"

int builtin_exit(t_command *cmd)
{
	(void)cmd;
	printf("Exiting minishell...\n");
	exit(EXIT_SUCCESS);
}
