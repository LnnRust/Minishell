#ifndef TOKENS_H
#define TOKENS_H

typedef enum {
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_HEREDOC,
	TOKEN_APPEND,
	TOKEN_WILDCARD,
} t_token_type;

typedef struct s_token {
	t_token_type	type;
	char			*value;
	struct s_token	*next;
} t_token;

//functions

t_token	*tokenizer(char *input);
t_token	*create_token(char *value, int type);
void	token_addback(t_token **token, t_token *new_token);
void	free_tokens(t_token *head);
void	print_tokens(t_token *head);
int		is_space(char c);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);

#endif // TOKENS_H
