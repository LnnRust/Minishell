#include "../includes/Minishell.h"

int	main(void)
{
	char	*input;

	while (1)
	{
		input = readline("minishell> ");
		if (!input) // if user -> Ctrl+D ( = signal eof -> need to exit)
		{
			printf("successfully exited minishell\n");
			break ;
		}
		if (*input)
			add_history(input);
				// add_history allows to keep commands and navigate with up/down
		tokenizer(input);
		free(input); // Readline allocates memory but doesnt free
	}
	return (0);
}
