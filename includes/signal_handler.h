#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

# include <signal.h>

void					signal_handler(volatile sig_atomic_t signo);
void					init_signal_handling();

#endif
