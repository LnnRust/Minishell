#include "../includes/Minishell.h"

//TODO need to build init env linked list function // DONE 
//TODO need one function for unset -> unset the var from env linked list // 
//TODO need one function to add var in env linked list

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*newstring;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		newstring = malloc(sizeof(char));
		if (!newstring)
			return (NULL);
		newstring[0] = '\0';
		return (newstring);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	newstring = malloc((len + 1) * sizeof(char));
	if (!newstring)
		return (NULL);
	while (s[start] && i < len)
		newstring[i++] = s[start++];
	newstring[i] = '\0';
	return (newstring);
}

static t_env *create_new_node(const char *key, const char *value)
{
	t_env *new;

	new = malloc(sizeof(t_env));
	if(!new)
		return NULL;
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

//init and fill env struct, returns pointer to head of linked list
t_env	*init_env_struct(char **envp)
{
	t_env	*head;
	t_env	*tail;
	t_env	*node;
	char	*equalChar;
	char	*key;
	int		i;

	i = 0;
	head = NULL;
	tail = NULL;
	while(envp[i])
	{
		equalChar = ft_strchr(envp[i], '=');
		if(equalChar)
		{
			key = (ft_substr(envp[i], 0, equalChar - envp[i]));
			node = create_new_node(key, equalChar + 1);
			free(key);
			if(!head)
			{
				head = node;
				tail = node;
			}
			else
				tail->next = node;
		}
		i++;
	}

	return (head);
}

//return value linked to the key, or NULL if key doesnt exists
char 	*get_env_value(t_env *env, char* key)
{
	while(env)
	{
		if(ft_strcmp(env->key, key) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

void free_env(t_env *env)
{

	t_env *tmp;
	while(env)
	{
		tmp = env->next;
		free(env->key);
		free(env->value);
		free(env);
	}
}