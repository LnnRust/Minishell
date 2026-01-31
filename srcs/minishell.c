#include "../includes/Minishell.h"

/// @brief Get the `PATH` environment variable.
/// @note The function name is a play on words, in reference
/// to the character "Passe-Partout" in the TV show "Fort-Boyard".
void	path_partout(void)
{
}

/// @brief Exit Minishell cleanly, freeing the structure `data` and all
/// of its members.
/// @brief - Can, in principle, be used at any stage of the program.
/// @brief - Checks if each member of the structure is already `NULL`
/// to avoid any double `free()`.
/// @param data Structure containing all the data dynamically allocated.
void	clean_exit(t_minishell_data *data)
{
	ft_printf("Exiting Minishell using clean_exit()...\n");
	envlst_clear(&data->env_list);
	token_lst_clear(&data->token_list);
	// envlst_print(&data->env_list);
	rl_clear_history();
	exit(EXIT_SUCCESS);
}

/// @brief Initialize Minishell.
/// @brief - Setup signal handling.
/// @brief - Get environment variables on start
/// and setup the linked list.
/// @brief - Greet the user : welcome !
/// @brief - Set prompt.
/// @param data Pointer to the main data structure.
void	init_minishell(t_minishell_data *data)
{
	init_signal_handling();
	data->env_list = init_env_lst();
	envlst_print(&data->env_list);
	ft_printf("=== Minishell ===\n");
	data->prompt = "minishell> ";

	// Process signal when received.
	int (*f_ptr)() = &react_to_signal;
	rl_event_hook = f_ptr;
}



/// @brief Main loop of Minishell.
/// @brief - "I almost wish I hadn't gone down that rabbit-hole."
/// @brief - You take the blue pill - the story ends, you wake up in your bed
/// and believe whatever you want to believe.
/// @brief - You take the red pill - you stay in Wonderland,
/// and I show you how deep the rabbit hole goes.
/// @param
/// @return
int	main(void)
{
	t_minishell_data	data;

	init_minishell(&data);
	while (1)
	{

		data.input = readline(data.prompt);
		if (data.input == NULL)
		{
			clean_exit(&data);
		}
		else
		{
			process_input(&data);
		}
	}
	return (0);
}
