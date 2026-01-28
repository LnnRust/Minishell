/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:03:19 by ancourti          #+#    #+#             */
/*   Updated: 2026/01/27 18:19:10 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/// @brief A command contains a list of tokens.
/// Each command is separated by a `|`, or nothing if it is the only command.
/// The output of each command may be "piped" to the input of another.
typedef struct s_command_lst
{
	// A command contains one or multiple tokens.
	struct s_token_lst		*command_content;
	struct s_command_lst	*next_command;
	struct s_command_lst	*previous_command;
}							t_command_lst;

/// @brief Types of token.
/// @note Selon Mylan : Il n'y aurait peut-être pas besoin de file et folder :
/// ```sh
/// < cat
/// ```
/// zsh: no such file or directory: cat
enum						e_token_types
{
	CMD,
	TXT,
	TOKEN_FILE,
	TOKEN_FOLDER,
	IN_REDIR,
	OUT_REDIR,
	HEREDOC,
	APPEND,
	PIPE
};

/// @brief A token contains a string.
/// A token may be :
/// @brief - A path to an executable.
/// @brief - A program (executable) in a known path,
/// such as in the PATH environment variable.
/// @brief - A relative path.
/// @brief - An absolute path.
typedef struct s_token_lst
{
	// Check `e_token_types` for supported types.
	int						token_type;
	// The raw token's content. Further processing may be needed,
	// such as expansions.
	char					*token_content;
	struct s_token_lst		*next_token;
	struct s_token_lst		*previous_token;
}							t_token_lst;

typedef struct s_minishell_data
{
	char					*input;
	char					*prompt;

	// cmd + ARG SANS REDIR
	char					**command_array;
	struct s_env_lst		*env_list;
	struct s_token_lst		*token_list;

	// À retirer plus tard.
	char					**env_array;
}							t_minishell_data;

#endif
