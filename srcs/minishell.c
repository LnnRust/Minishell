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

/// @brief Exit Minishell cleanly, freeing the structure `data` and all
/// of its members.
/// @brief - Can, in principle, be used at any stage of the program.
/// @brief - Checks if each member of the structure is already `NULL`
/// to avoid any double `free()`.
/// @param data Structure containing all the data dynamically allocated.
void	clean_exit(t_minishell_data *data)
{
	ft_printf("clean_exit()\n");
	envlst_clear(&data->env_list);
	// envlst_print(&data->env_list);
	rl_clear_history();
	// exit(EXIT_SUCCESS);
}

volatile sig_atomic_t g_signal;

/// Handle the signal received. (ex: SIGINT exits the program).
/// @param signo Signal Number. You may also enter the signal's short name,
/// `SIGINT` for example. Check this page for some more info :
/// https://faculty.cs.niu.edu/~hutchins/csci480/signals.htm
/// @warning Address Sanitizer (memory leak check) MAY FAIL to report leaks,
/// depending on how the signal handler is implemented.
/// @warning - The `exit()` function, including `atexit()`, `quick_exit()`,
/// etc... can skip ASan entirely. In this scenario, only Valgrind can detect
/// memory leaks on `exit()`.
/// @note - The future implementation should not use the `exit()` function.
/// @note - It may in the future use either `signal()` or `sigaction()`.
void	signal_handler(volatile sig_atomic_t signo)
{
	g_signal = signo;

	if (signo == SIGINT)
	{
		// https://stackoverflow.com/questions/16828378/readline-get-a-new-prompt-on-sigint
		ft_printf("\nSIGINT\n"); // New line.
		rl_on_new_line(); // Regenerate the prompt on a newline
		rl_replace_line("", 0); // Clear the previous text
		rl_redisplay();
	}
	if (signo == SIGQUIT)
	{
		//rl_on_new_line(); // Regenerate the prompt on a newline
		//rl_replace_line("", 0); // Clear the previous text
		rl_redisplay();
	}



	// if (signo == SIGINT)
	// {
	// 	ft_printf("\nReceived SIGINT, TERMINATING.\n");
	// 	ft_printf("Next version will not terminate, and will prompt back.\n");
	// 	ft_printf("\033[0;31m=== WARNING: calling exit() ===\033[0m\n");
	// 	ft_printf("\033[0;31mAddress Sanitizer will be skipped. NO LEAKS WILL BE REPORTED !\033[0m\n");
	// 	ft_printf("\033[0;31m\nOnly Valgrind can report leaks in this scenario.\033[0m\n");
	// 	exit(EXIT_SUCCESS);
	// }
}

/// @brief Initialize Minishell.
/// @brief - Setup signal handling.
/// @brief - Get environment variables on start and setup the linked list.
/// @brief - Greet the user : welcome !
/// @param data Pointer to the main data structure.
void init_minishell(t_minishell_data *data)
{
	init_signal_handling();
	data->env_list = init_env_lst();
	envlst_print(&data->env_list);

	ft_printf("=== Minishell ===\n");
}

int	main(void)
{
	t_minishell_data	data;

	init_minishell(&data);
	while (1)
	{
		data.input = readline("minishell> ");
		if (data.input == NULL)
		{
			ft_printf("Got EOF. Exiting Minishell...\n");
			clean_exit(&data);
			return (0);
		}
		else
		{
			add_history(data.input);
			data.command_array = ft_split(data.input, ' ');
			if (data.command_array[0] != NULL)
			{
				data.env_array = env_lst_to_str_array(data.env_list);
				execve(data.command_array[0], data.command_array, data.env_array);
				ft_free_str_array(data.env_array);
			}
			ft_free_str_array(data.command_array);
			free(data.input);
		}
	}
	return (0);
}
