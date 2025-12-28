#ifndef TOKENS_H
#define TOKENS_H

typedef enum {
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_HEREDOC,
	TOKEN_APPEND,
} t_token_type;

typedef struct s_token {
	t_token_type	type;
	struct s_token	*next;
	char			*value;
} t_token;

//functions

int		is_space(char c);
int		find_end_of_word(char *word);
t_token	*create_token(char *value, int type);
void	token_addback(t_token **token, t_token *new_token);
void tokenizer(char *input);

#endif // TOKENS_H
