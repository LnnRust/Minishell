#include "../includes/Minishell.h"

/// @brief Signal Handler. Describes what actions to do depending on the
/// signal received. (ex: SIGINT exits the program).
/// @param signo Signal Number. You may also enter the signal's short name,
/// `SIGINT` for example. Check this page for some more info :
/// https://faculty.cs.niu.edu/~hutchins/csci480/signals.htm
void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_printf("\nReceived SIGINT, TERMINATING.\n");
		ft_printf("Next version will not terminate, and will prompt back.\n");
		//ft_printf("minishell>");
		exit(EXIT_SUCCESS);
	}
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
void	init_signal_handling(struct sigaction *sa)
{
	ft_bzero(sa, sizeof(*sa));
	sa->sa_handler = &signal_handler;
	sigemptyset(&sa->sa_mask);
	sa->sa_flags = SA_SIGINFO;
	sigaction(SIGINT, sa, NULL);
	if (sigaction(SIGINT, sa, NULL) == -1)
	{
		ft_printf("\nError : Can't catch SIGINT. TERMINATING\n");
		exit(EXIT_FAILURE);
	}
	sigaction(SIGUSR1, sa, NULL);
	if (sigaction(SIGUSR1, sa, NULL) == -1)
	{
		ft_printf("\nError : Can't catch SIGUR1. TERMINATING\n");
		exit(EXIT_FAILURE);
	}
}
