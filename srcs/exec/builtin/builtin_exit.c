/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:49:57 by mehdi             #+#    #+#             */
/*   Updated: 2026/03/04 07:42:34 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_all(t_envp *envp, t_shell *shell)
{
	if (!envp)
		return ;
	if (shell && shell->digit)
	{
		if (shell->digit->fd_inf > STDERR_FILENO)
			close(shell->digit->fd_inf);
		if (shell->digit->fd_outf > STDERR_FILENO)
			close(shell->digit->fd_outf);
		if (shell->digit->save_in > STDERR_FILENO)
			close(shell->digit->save_in);
		if (shell->digit->save_out > STDERR_FILENO)
			close(shell->digit->save_out);
		free(shell->digit);
	}
	free_loop_data(envp);
	free_envp(envp);
	free_env_list(envp->env_list);
	free(envp);
	free(shell);
}

int	ft_nb_args(char **cmd)
{
	int	nb_args;

	nb_args = 0;
	while (cmd[nb_args] && cmd[nb_args][0])
		nb_args++;
	return (nb_args);
}

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_overflow(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (result > (LONG_MAX - (str[i] - '0')) / 10)
			return (1);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	(void)sign;
	return (0);
}

bool	builtin_exit(char **cmd, int g_status, t_envp *envp, t_shell *shell)
{
	int	nb_args;
	int	exit_code;

	nb_args = ft_nb_args(cmd);
	if (isatty(STDIN_FILENO))
		printf("exit\n");
	if (cmd[1] == NULL)
	{
		free_all(envp, shell);
		exit(g_status);
	}
	if (!is_valid_number(cmd[1]) || is_overflow(cmd[1]))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		free_all(envp, shell);
		exit(255);
	}
	if (nb_args > 2)
		return (ft_putstr_fd("minishell: exit: too many arguments\n"
				, 2), false);
	exit_code = (unsigned char)ft_atoi(cmd[1]);
	free_all(envp, shell);
	exit(exit_code);
}
