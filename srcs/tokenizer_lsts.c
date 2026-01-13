#include "../includes/Minishell.h"

// Implementation of tokenizer linked lists would go here

t_token	*create_token(char *value, int type)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->value = value;
	new_token->type = type;
	new_token->next = NULL;
	return (new_token);
}

void	token_addback(t_token **token, t_token *new_token)
{
	t_token	*tmp;

	if (!token || !new_token)
		return ;
	if (!*token)
	{
		*token = new_token;
		return ;
	}
	tmp = *token;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_token;
	return ;
}
