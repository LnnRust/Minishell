#include "../includes/Minishell.h"

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

	init_signal_handling(&sa);
	while (1)
	{
		input = readline("minishell> ");
		if (input == NULL) // if user -> Ctrl+D ( = signal eof -> need to exit)
		{
			ft_printf("Got EOF. Exiting Minishell...\n");
			// We should execute the built-in exit() command here.
			exit(EXIT_SUCCESS);
		}
		else
		{
			add_history(input);
				// add_history allows to keep commands and navigate with up/down
			// tokenizer(input);
			free(input); // Readline allocates memory but doesnt free
		}
	}
	return (0);
}
