#include "../includes/Minishell.h"

int main(void)
{
	char	*input;
	t_token	*tokens;
	while (1)
	{
		input = readline("minishell> ");
		if (!input || input[0] == '\0')  // if user -> Ctrl+D ( = signal eof -> need to exit)
		{
			printf("successfully exited minishell\n");
			break;
		}
		if (*input)
			add_history(input);  // add_history allows to keep commands and navigate with up/down
		tokens = tokenizer(input);
		print_tokens(tokens);
		if(!tokens)
			return (free(input), free_tokens(tokens), EXIT_FAILURE);
		free(input);  // Readline allocates memory but doesnt free
	}
	return (0);
}
