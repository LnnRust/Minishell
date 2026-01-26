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
}

/// @brief There comes the horrible stuff.
/// @brief "I almost wish I hadn't gone down that rabbit-hole."
/// @param data Pointer to the main data structure.
void	process_input(t_minishell_data *data)
{
	add_history(data->input);
	data->command_array = ft_split(data->input, ' ');
	if (data->command_array[0] != NULL)
	{
		data->env_array = env_lst_to_str_array(data->env_list);
		execve(data->command_array[0], data->command_array, data->env_array);
		ft_free_str_array(data->env_array);
	}
	ft_free_str_array(data->command_array);
	free(data->input);
}

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
