#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

# include <signal.h>

void	signal_handler(int signo);
void	init_signal_handling(struct sigaction *sa);

#endif
