#include "../includes/Minishell.h"

/// @brief Get the `PATH` environment variable.
/// @note The function name is a play on words, in reference
/// to the character "Passe-Partout" in the TV show "Fort-Boyard".
void	path_partout(void)
{
}

/// @brief Check if a character is whitespace, as defined by the
/// ISO C Standard.
/// Whitespace characters include the following :
/// `' '`, `\t`, `\n` , `\v`, `\f` and `\r`.
/// @param c Character to check.
/// @return True (1) or False (0).
int	ft_is_whitespace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
	{
		return (1);
	}
	return (0);
}

/// @brief Some useful stuff to know.
///
/// - `CTRL+D` sends an EOF.
///
/// - If `readline()` sees an EOF, it returns NULL.
///
/// The readline function is great. It manages for us the history using
/// @param
/// @return

int	main(void)
{
	char				*input;
	struct sigaction	sa;
	char				**command;
	t_env_lst			*env_vars;
	int i;

	//command = NULL;
	env_vars = init_env_lst();

	//free(env_vars);

	//ft_printf("%p\n", env_vars);

	envlst_print(&env_vars);
	envlst_clear(&env_vars);
	init_signal_handling(&sa);
	ft_printf("=== Minishell ===\n");
	while (1)
	{
		input = readline("minishell> ");
		if (input == NULL)
		{
			ft_printf("Got EOF. Exiting Minishell...\n");
			// We should execute the built-in exit() command here.
			exit(EXIT_SUCCESS);
		}
		else
		{
			add_history(input);
			command = ft_split(input, ' ');
			if (command[0] != NULL)
			{
				execve(command[0], command, NULL);
			}
			// This is used to free the array of strings each time.
			i = 0;
			while (command[i] != NULL)
			{
				i++;
			}
			while (i >= 0)
			{
				free(command[i]);
				i--;
			}
			free(command);
			free(input);
		}
	}
	return (0);
}
