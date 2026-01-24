#include "../includes/Minishell.h"

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
	t_token *tmp;
	if (!token || !new_token)
		return ;
	if(!*token)
	{
		*token = new_token;
		return ;
	}
	tmp = *token;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = new_token;
	return ;
}

void	free_tokens(t_token *head)
{
	t_token *tmp;
	while(head)
	{
		tmp = head;
		head = head->next;
		free(tmp->value);
		free(tmp);
	}
}

// debug function
void	print_tokens(t_token *head)
{
	t_token *tmp = head;
	while(tmp)
	{
		printf("Token Type: %d, Value: %s\n", tmp->type, tmp->value);
		tmp = tmp->next;
	}
}

