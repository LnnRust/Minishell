/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:19:32 by ancourti          #+#    #+#             */
/*   Updated: 2026/01/27 20:29:54 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/// @brief There comes the horrible stuff.
/// @brief - "The Matrix has you... Follow the white rabbit. Knock, Knock, Neo."
/// @param data Pointer to the main data structure.
void	process_input(t_minishell_data *data)
{
	add_history(data->input);
	data->command_array = ft_split(data->input, ' ');
	if (data->command_array[0] != NULL)
	{
		data->env_array = env_lst_to_str_array(data->env_list);
		create_token_lst(data);
		execve(data->command_array[0], data->command_array, data->env_array);
		ft_free_str_array(data->env_array);
		token_lst_clear(&data->token_list);
	}
	ft_free_str_array(data->command_array);
	free(data->input);
}

/// @brief Allocates memory (using `malloc()`) and returns
/// a new node.
///
/// - The `content` member variable is
/// initialized with the given parameter `content`.
/// @param value The value (`int`) to give to the element.
/// @return A pointer to the new node.
t_token_lst	*token_lst_new(char *value)
{
	t_token_lst	*new_stack;

	new_stack = malloc(sizeof(t_token_lst));
	if (new_stack == NULL)
	{
		return (NULL);
	}
	new_stack->token_content = value;
	new_stack->next_token = NULL;
	new_stack->previous_token = NULL;
	return (new_stack);
}
/// @brief Adds the item `new` at the end of the stack.
/// @param stack The address of a pointer to the first node of a stack.
/// @param new The address of a pointer to the node to be added.
void	token_lst_add_back(t_token_lst **stack, t_token_lst *new)
{
	t_token_lst	*last_element;

	last_element = token_lst_last(*stack);
	if (last_element == NULL)
	{
		*stack = new;
		return ;
	}
	last_element->next_token = new;
	new->previous_token = last_element;
}

// @brief Takes a node as parameter and frees its content
// using the function `del`. Free the node itself but
// does NOT free the next node.
// @param lst The node to free.
// @param del The address of the function used to delete the content.
void	token_lst_del_one(t_token_lst *stack)
{
	free(stack->token_content);
	free(stack);
}

// @brief Deletes and frees the given node and all its successors,
// using the function `del` and `free()`.
// Finally, set the pointer to the list to `NULL`.
//
// Source code explaination :
//
// 1. Loop over the list.
//
// 2. Set `temp` to point to the next element of the list.
//
// 3. Use `ft_lstdelone()` on the current element.
//
// 4. Set the list pointer equal to `temp`, so that we have a
// pointer to the next element.
//
// 5. Finally, `free()` the list pointer and set it to `NULL`.
// @param lst The address of a pointer to a node.
// @param del The address of the function used to
// delete the content of the node.
void	token_lst_clear(t_token_lst **stack)
{
	t_token_lst	*temp;

	while ((*stack) != NULL)
	{
		temp = (*stack)->next_token;
		token_lst_del_one(*stack);
		*stack = temp;
	}
	free(*stack);
	*stack = NULL;
}

/// @brief Print the contents of the stack using `ft_printf()`.
/// @param stack Pointer to the first node of the stack.
void	token_lst_print(t_token_lst **stack)
{
	t_token_lst	*temp;
	int			i;

	if (*stack == NULL)
	{
		ft_printf("Empty stack");
		return ;
	}
	// ft_printf("\n----- STACK CONTENTS -----\n");
	i = 0;
	temp = *stack;
	while (temp->next_token != NULL)
	{
		ft_printf("Node %i = %s | Node Address : %p | Prev. : %p | Next : %p\n",
			i, temp->token_content, temp->token_content, temp->previous_token,
			temp->next_token);
		temp = temp->next_token;
		i++;
	}
	ft_printf("Node %i = %s | Node Address : %p | Prev. : %p | Next : %p\n", i,
		temp->token_content, temp->token_content, temp->previous_token,
		temp->next_token);
}

/// @brief Returns the last node of the stack.
/// @param stack The beginning of the stack.
/// @return Last node of the stack.
t_token_lst	*token_lst_last(t_token_lst *stack)
{
	t_token_lst	*ptr_stack;

	if (stack == NULL)
	{
		return (NULL);
	}
	ptr_stack = stack;
	while (ptr_stack->next_token != NULL)
	{
		ptr_stack = ptr_stack->next_token;
	}
	return (ptr_stack);
}

// @brief Deletes and frees the given node and all its successors,
// using the function `del` and `free()`.
// Finally, set the pointer to the list to `NULL`.
//
// Source code explaination :
//
// 1. Loop over the list.
//
// 2. Set `temp` to point to the next element of the list.
//
// 3. Use `ft_lstdelone()` on the current element.
//
// 4. Set the list pointer equal to `temp`, so that we have a
// pointer to the next element.
//
// 5. Finally, `free()` the list pointer and set it to `NULL`.
// @param lst The address of a pointer to a node.
// @param del The address of the function used to
// delete the content of the node.
void	ft_stack_clear(t_token_lst **stack)
{
	t_token_lst	*temp;

	while ((*stack) != NULL)
	{
		temp = (*stack)->next_token;
		token_lst_del_one(*stack);
		*stack = temp;
	}
	free(*stack);
	*stack = NULL;
}

// Now you must create the tokens. Face the devil.

/// @brief Splits the raw input line from`data->input` into tokens.
/// Tokens are separated by "whitespace" as defined by the ISO C Standard.
/// @brief Whitespaces are removed when each token is put into a linked list.
/// @brief - The token list is initialized progressively,
/// as each token is detected in the loop.
/// @brief - If there are no tokens,
///	an empty list is given. Why not a `NULL` pointer ?
/// @note The linked list is dynamically allocated. It must be `free()`d.
/// @param data Pointer to the main data structure.
void	create_token_lst(t_minishell_data *data)
{
	int			i;
	int			begining_of_next_token;
	t_token_lst	*first_node;

	first_node = NULL;
	i = 0;
	// begining_of_next_token = 0;
	// Skip spaces until a valid chacter is found
	while (ft_is_whitespace(data->input[i]) && data->input[i] != '\0')
	{
		i++;
	}
	begining_of_next_token = i;
	while (data->input[i] != '\0')
	{
		// Spaces at the beggining have been skipped.
		// Skip up to the end or the next white space,
		// which will be the end position of the token to copy.
		while (!ft_is_whitespace(data->input[i]) && data->input[i] != '\0')
		{
			i++;
		}
		// Here you have a token, copy it.
		if (first_node == NULL)
		{
			first_node = token_lst_new(ft_substr(data->input,
						begining_of_next_token, (i - begining_of_next_token)));
		}
		else
		{
			token_lst_add_back(&first_node, token_lst_new(ft_substr(data->input,
						begining_of_next_token, (i - begining_of_next_token))));
		}
		while (ft_is_whitespace(data->input[i]) && data->input[i] != '\0')
		{
			i++;
		}
		// If at the end of the string, that's it, stop, you got the last token.
		if (data->input[i] == '\0')
		{
			break ;
		}
		else
		{
			begining_of_next_token = i;
		}
	}
	// Add last token to the linked list.
	token_lst_add_back(&first_node, token_lst_new(NULL));
	// If there are only whitespaces, maybe the linked list should be NULL.
	token_lst_print(&first_node);
}
