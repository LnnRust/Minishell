#include "../includes/Minishell.h"

volatile sig_atomic_t	g_signal;

/// @brief Updates the global variable `g_signal` when a signal is received.
/// Is garanteed to run in a very small amount of CPU cycles.
/// @param signo Signal Number. You may also enter the signal's short name,
/// `SIGINT` for example. Check this page for some more info :
/// https://faculty.cs.niu.edu/~hutchins/csci480/signals.htm
void	signal_handler(volatile sig_atomic_t signo)
{
	g_signal = signo;
}

/// @brief Most of the code in here was part of the signal handler, before
/// Chayane broke it.
/// @note - It may in the future use either `signal()` or `sigaction()`.
int	react_to_signal()
{
	if (g_signal == SIGINT)
	{
		// https://stackoverflow.com/questions/16828378/readline-get-a-new-prompt-on-sigint
		ft_printf("\nSIGINT\n"); // New line.
		rl_on_new_line();        // Regenerate the prompt on a newline
		rl_replace_line("", 0);  // Clear the previous text
		rl_redisplay();
	}
	else if (g_signal == SIGQUIT)
	{
		// rl_on_new_line(); // Regenerate the prompt on a newline
		// rl_replace_line("", 0); // Clear the previous text
		rl_redisplay();
	}
	// Reset the signal.
	g_signal = 0;
	return (0);
}

/// @brief Initialize the signal handling structure.
/// Exits the program if something fails.
void	init_signal_handling(void)
{
	// SIG_DFL;
	// SIG_IGN;
	if (signal(SIGINT, signal_handler) == SIG_ERR)
	{
		ft_printf("An error occurred while setting a signal handler.\n");
		exit(EXIT_FAILURE);
	}
	if (signal(SIGQUIT, signal_handler) == SIG_ERR)
	{
		ft_printf("An error occurred while setting a signal handler.\n");
		exit(EXIT_FAILURE);
	}
}
