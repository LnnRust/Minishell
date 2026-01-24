#include "../../includes/Minishell.h"

int builtin_pwd(t_command *cmd)
{
	char cwd[1024];

	(void)cmd;
	if (getcwd(cwd, sizeof(cwd)))
	{
		printf("%s\n", cwd);
		return (EXIT_SUCCESS);
	}
	else
	{
		perror("pwd error\n");
		return (EXIT_FAILURE);
	}
}
