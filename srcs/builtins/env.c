#include "../../includes/Minishell.h"

int	builtin_env(t_command *cmd)
{
	int	i;

	i = 0;
	if (!cmd || !cmd->envp) // means -> env (empty) = not an error in bash
		return (EXIT_SUCCESS);
	if (cmd->args[1])
	{
		printf("env: too many arguments\n");
		return (127);
	}
	while (cmd->envp[i])
	{
		if (ft_strchr(cmd->envp[i], '='))
			printf("%s\n", cmd->envp[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
