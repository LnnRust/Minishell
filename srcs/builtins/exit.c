#include "../../includes/Minishell.h"

int	builtin_exit(t_command *cmd)
{
	(void)cmd;
	printf("Exiting minishell...\n");
	exit(EXIT_SUCCESS);
}
