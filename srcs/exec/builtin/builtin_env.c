/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:49:54 by mehdi             #+#    #+#             */
/*   Updated: 2026/03/04 07:07:31 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool    builtin_env(t_envp *c)
{
    void    (*old_sigpipe)(int);
    int        i;
    int        j;
    ssize_t    ret;

    i = 0;
    j = -1;
    old_sigpipe = signal(SIGPIPE, SIG_IGN);
    while (c->env[i])
    {
        while(c->env[i][++j])
        {
            if (c->env[i][j] && c->env[i][j] == '=')
            {
                ret = write(1, c->env[i], ft_strlen(c->env[i]));
                if (ret == -1 && errno == EPIPE)
                    break ;
                write(1, "\n", 1);
                break ;
            }
            j++;
        }
        j = -1;
        i++;
    }
    signal(SIGPIPE, old_sigpipe);
    return (true);
}