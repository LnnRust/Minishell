/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:49:44 by mehdi             #+#    #+#             */
/*   Updated: 2026/03/03 23:35:27 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_args(char **cmd, int i, bool new_line)
{
	ft_putstr_fd(cmd[i], 1);
	if (cmd[i + 1] != NULL)
		write(1, " ", 1);
	else if (cmd[i + 1] == NULL && new_line == true)
		write (1, "\n", 1);
	else if (!cmd[i + 1] && !new_line)
		write(1, "%\n", 2);
}

static bool	find_option(char **cmd, int i, bool new_line)
{
	int	j;

	while (cmd[i] && cmd[i][0] == '-')
	{
		j = 1;
		while (cmd[i][j] == 'n')
			j++;
		if (cmd[i][j] != '\0')
			break ;
		new_line = false;
		i++;
	}
	if (!cmd[i] && new_line)
	{
		write(1, "\n", 1);
		return (new_line);
	}
	while (cmd[i])
	{
		print_args(cmd, i, new_line);
		i++;
	}
	return (new_line);
}

bool	builtin_echo(char **cmd)
{
	int		i;
	bool	new_line;

	i = 1;
	new_line = true;
	if (!cmd || !cmd[0])
	{
		write(1, "\n", 1);
		return (true);
	}
	new_line = find_option(cmd, i, new_line);
	return (true);
}
