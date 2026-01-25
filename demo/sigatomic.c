#include <signal.h>
#include <stdio.h>
#include <unistd.h>

// Source : https://www.linuxquestions.org/questions/programming-9/how-to-pass-input-to-a-signal-handler-665810/

sig_atomic_t volatile done = 0;

void	handler(int num)
{
	done = 1;
}

int	main(void)
{
	signal(SIGALRM, handler);
	alarm(10);
	while (!done)
		puts("Hello World");
	return (0);
}
