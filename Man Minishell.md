# Minishell documentation

Execute a simple command using minishell using the `execve()` syscall.

Command to execute :
```sh
cat bonjour
```

Prerequisites :
- Path : execute for example `/bin/cat`.
- argv : tableau de paramètres.
- envp : tableau de variables d'environnement.

# Initial statements

After messing around a bit, I quickly found that my way of executing a command has major flaws and limit. It is sketchy to not say the least :

```C
input = readline("minishell> ");
if (input == NULL)
{
	ft_printf("Got EOF. Exiting Minishell...\n");
	// We should execute the built-in exit() command here.
	exit(EXIT_SUCCESS);
}
else
{
	add_history(input);
	command = ft_split(input, ' ');
	if (command[0] != NULL)
	{
		execve(command[0], command, NULL);
	}
	// This is used to free the array of strings each time.
	int i;
	i = 0;
	while(command[i] != NULL)
	{
		i++;
	}
	while(i >= 0)
	{
		free(command[i]);
		i--;
	}
	free(command);
	free(input);
}
```

So I looked at how it is done in Bash. This book describes some useful stuff and highlights keypoints that I should take into account to create the acrchitecture of Minishell :
https://www.oreilly.com/library/view/learning-the-bash/1565923472/

Some people advised me to take into account the possibility to do :

✨ Analyse récursive descendante ✨

# How Bash *seems* to do the magic - aka : the rabbit hole

This section is mainly knowledge I gathered from "Chapter 7: Input/Output and Command-Line Processing" in the book "Learning the Bash".

This can be how Minishell will do the magic.

Bash makes a distinction between work and token.

## Step 0 - Pipeline

One command line equals one pipeline : there is **only one pipeline**.

The pipeline is a list of all the commands to execute, separated by zero or multiple `|` characters.

For each pipeline, the shell breaks it up into commands, sets up the I/O for the pipeline, then does the following steps.

### Step 0.1 - Parse errors

There cannot be more than two `|` together, like so : `||`. If we have let's say `|||`, we should print an error message :

```
syntax error near unexpected token '|'
```

## Step 1 - Split into tokens

Each command in the pipeline, is split into tokens.

In Minishell, tokens are separated by "whitespace", as defined by the ISO C Standard. This includes the following characters : `' '`, `\t`, `\n` , `\v`, `\f` and `\r`.

## Step 2 - Check if 1st token is keyword

We check if the first token is a keyword. Keywords include for example "if", control structures...

> This is not supported in Minishell.

## Step 3 - Check if 1st token is an Alias

> This is not supported in Minishell.


## Step 4 - Brace expansion

https://www.gnu.org/software/bash/manual/html_node/Brace-Expansion.html

> This is not supported in Minishell.

## Step 5 - Tilde expansion

Substitutes the user’s home directory ($HOME) for tilde if it is at the beginning of a *word*. Substitutes user’s home directory for `~user.`*

## Step 6 - Parameter (variable) expansion

Performs parameter (variable) substitution for any expression that starts with a
dollar sign `($)`.

> WARNING : can be "recursive".

## Step 7 - Command substitution

Does command substitution for any expression of the form $(string).

## Step 8 - Arithmetic substitution

Evaluates arithmetic expressions of the form $((string)).

> This is not supported in Minishell.

## Step 9 - Word splitting

word splitting

## Step 10 - Pathname expansion

Performs pathname expansion, a.k.a. wildcard expansion, for any occurrences of
*, ?, and [/] pairs.

> This will be partially be supported in Minishell.

## Step 11 - Command lookup: function, built-in command, executable file

Uses the first word as a command by looking up its source :
- as a function command
- then as a built-in
- then as a file in any of the directories in `$PATH`.

## Step 12 - Run the command

Runs the command after setting up I/O redirection and other such things

`$?` defaults to zero (0) when starting `bash`. This will be replicated in minishell.

### 12.1 - Command lookup order

1. Functions (not supported)
2. Built-ins
3. Scripts (not supp)
4. Executables

> Minishell does not support Bash scripts.

# Quotes

Quotes can skip some of the above steps.

- Single quotes (`‘’`) bypass everything through Step 10—including aliasing. All
characters inside a pair of single quotes are untouched. You can’t have single
quotes inside single quotes—not even if you precede them with backslashes.*

- Double quotes (`“”`) bypass Steps 1 through 4, plus steps 9 and 10. That is, they
ignore pipe characters, aliases, tilde substitution, wildcard expansion, and split-
ting into words via delimiters (e.g., blanks) inside the double quotes. Single
quotes inside double quotes have no effect. But double quotes do allow parame-
ter substitution, command substitution, and arithmetic expression evaluation.
You can include a double quote inside a double-quoted string by preceding it
with a backslash (`\`). You must also backslash-escape `$`, (the archaic command
substitution delimiter), and `\` itself.

Find a way to put the command + arguments into an array of strings.
- Issue if there is only a space.


Find a way to put the environment variables into an array of strings.

# Getting the environment variables to work

The `__environ` variable contains the environment variables at the start of Minishell in a an `NULL` pointer terminated array of strings (`char **`). This variable is NOT updated while the program is running.

Because we want to be able to add or remove environment values after start, we need to have them in a chained list that we can update while Minishell is running.

At start, Minishell reads the environment variables from `__environ` and converts them to a chained list. The structure of the chained lsit looks like this. It is initialized using the following function :
```C
typedef struct s_env_lst
{
	char				*env_key;
	char				*env_value;
	struct s_env_lst	*next_env;
}						t_env_lst;

// Read environ, initialize and fill the chained list.
t_env_lst *init_env_lst(char **environ);
```

Problem : The `execve()` function expects to get the environment variables in the same format as `__environ`, that is, a NULL pointer terminated array of strings. So we need to do the oposite conversion **each time** we call `execve()` to get the current up to date environment variables, as they may have been modified by the previous command.

> Failure to do so properly will result in unexpected results, or crashes.

The opposite conversion of the chained list before calling `execve()` is done using this function :

```C
char	**env_lst_to_str_array(t_env_lst *lst);
```

The `env` (built-in) command may also remove or add any env variable to/from the chained list.

This variable **must be freed** right after doing the `execve()` to avoid leaks.
