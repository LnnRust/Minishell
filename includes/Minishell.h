#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
#include "tokens.h"
#include "parsing.h"
#include "builtins.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

t_env	*init_env_struct(char **envp);
int		handle_expand(int *i, int *j, t_env *env, char *str, char *result, int exit_status);
int		find_expand_len(char *str, t_env *env, int exit_status);
char	*expand_env_vars(char *str, t_env *env, int exit_status);
char	*extract_var_name(char *str, int start);
char    *get_env_value(t_env *env, char* key);
void	free_env(t_env *env);

#endif

