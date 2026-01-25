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
	clear_history();
	rl_clear_history();
	// exit(EXIT_SUCCESS);
}


volatile sig_atomic_t g_signal;

/// signal received. (ex: SIGINT exits the program).
/// @param signo Signal Number. You may also enter the signal's short name,
/// `SIGINT` for example. Check this page for some more info :
/// https://faculty.cs.niu.edu/~hutchins/csci480/signals.htm
/// @warning Address Sanitizer (memory leak check) WILL FAIL due to how the
/// signal handler is implemented. The `exit()` functions skips ASan entirely.
/// Only Valgrind can detect memory leaks if using `exit()`.
/// @note - The future implementation should not use the `exit()` function.
/// @note - It may rely on `signal()` instead of `sigaction()`.
void	signal_handler(volatile sig_atomic_t signo)
{
	g_signal = signo;
	ft_printf("\n");
	rl_on_new_line(); // Regenerate the prompt on a newline
    rl_replace_line("", 0); // Clear the previous text
	rl_redisplay();

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

int	main(void)
{
	t_minishell_data	data;

	// struct sigaction	sa;
	// Set above function as signal handler for the SIGINT signal:
	// Warning : SIGINT leaks the whole data structure,
	//	because it is not freed at all.
	if (signal(SIGINT, signal_handler) == SIG_ERR)
	{
		ft_printf("An error occurred while setting a signal handler.\n");
		return (EXIT_FAILURE);
	}
	data.env_list = init_env_lst();
	envlst_print(&data.env_list);
	// init_signal_handling(&sa);
	ft_printf("=== Minishell ===\n");
	while (1)
	{
		//rl_catch_signals = 0;
		rl_persistent_signal_handlers = 0;
		data.input = readline("minishell> ");
		if (g_signal == SIGINT)
		{
			ft_printf("GOTCHA !\n");
		}
		g_signal = 0;
		if (data.input == NULL)
		{
			ft_printf("Got EOF. Exiting Minishell...\n");
			clean_exit(&data);
			return (0);
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
