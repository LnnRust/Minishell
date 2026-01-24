#ifndef PARSING_H
#define PARSING_H

typedef struct s_command
{
	char				**args;
	int					input_fd;
	int					output_fd;
	struct s_command	*next;
}	t_command;

#endif // PARSING_H
