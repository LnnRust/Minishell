#include "../includes/Minishell.h"

volatile sig_atomic_t	g_signal;

/// @brief Updates the global variable `g_signal` when a signal is received.
/// A signal handler should not do anything else except this, as
/// recommended

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
}

int	react_to_signal()
{
	if (g_signal == SIGINT)
	{
		// https://stackoverflow.com/questions/16828378/readline-get-a-new-prompt-on-sigint
		ft_printf("\nSIGINT\n"); // New line.
		rl_on_new_line();        // Regenerate the prompt on a newline
		rl_replace_line("", 0);  // Clear the previous text
		rl_redisplay();
		//g_signal = SIG_DFL;
	}
	if (g_signal == SIGQUIT)
	{
		// rl_on_new_line(); // Regenerate the prompt on a newline
		// rl_replace_line("", 0); // Clear the previous text
		rl_redisplay();
		//g_signal = SIG_DFL;
	}
	g_signal = 0;
	// if (signo == SIGINT)
	// {
	// 	ft_printf("\nReceived SIGINT, TERMINATING.\n");
	// 	ft_printf("Next version will not terminate, and will prompt back.\n");
	// 	ft_printf("\033[0;31m=== WARNING: calling exit() ===\033[0m\n");
	// 	ft_printf("\033[0;31mAddress Sanitizer will be skipped. NO LEAKS WILL BE REPORTED !\033[0m\n");
	// 	ft_printf("\033[0;31m\nOnly Valgrind can report leaks in this scenario.\033[0m\n");
	// 	exit(EXIT_SUCCESS);
	// }
	return (0);
}

/// @brief Initialize the signal handling structure.
/// Exits the program if something fails.
/// @param sa Signal handling structure pointer
/// @note How it works :
/// @note - Declare the sigaction structure
/// @note - Set all of the structure's bits to 0 to avoid errors
/// related to uninitialized variables...
/// @note - Set the signal handler as the default action when a
/// a signal is received by the program.
/// @note Apply the action in the structure to the
/// SIGINT, SIGUSR1 and SIGUSR2 signals.
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
