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

void	clean_exit(t_minishell_data *data)
{
	envlst_clear(&data->env_list);
	exit(EXIT_SUCCESS);
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
	struct sigaction	sa;
	t_minishell_data	data;

	data.env_list = init_env_lst();
	// free(env_vars);
	// ft_printf("%p\n", env_vars);
	envlst_print(&data.env_list);
	init_signal_handling(&sa);
	ft_printf("=== Minishell ===\n");
	while (1)
	{
		data.input = readline("minishell> ");
		if (data.input == NULL)
		{
			ft_printf("Got EOF. Exiting Minishell...\n");
			// We should execute the built-in exit() command here.
			// clean_exit();
			clean_exit(&data);
		}
		else
		{
			add_history(data.input);
			data.command = ft_split(data.input, ' ');
			if (data.command[0] != NULL)
			{
				data.env_array = env_lst_to_str_array(data.env_list);
				execve(data.command[0], data.command, data.env_array);
				ft_free_str_array(data.env_array);
			}
			ft_free_str_array(data.command);
			free(data.input);
		}
	}
	return (0);
}
