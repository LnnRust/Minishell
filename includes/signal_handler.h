#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

# include "Minishell.h"

void	signal_handler(volatile sig_atomic_t signo);
void	init_signal_handling(void);
int		react_to_signal(void);

#endif
