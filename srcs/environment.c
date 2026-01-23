/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:48:36 by ancourti          #+#    #+#             */
/*   Updated: 2026/01/23 14:36:54 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/// @brief Make environment variable lst.
/// @brief - Run in the table
/// @return `NULL` (pointer)-terminated list of pointers to
/// `null` (`\n`) terminated strings.
t_env_lst	*init_env_lst()
{
	int			i;
	t_env_lst	*env_lst_first;
	i = 0;

	// while (__environ[i] != NULL)
	// {
	// 	ft_printf("%s\n", __environ[i]);
	// 	i++;
	// }

	i = 0;
	env_lst_first = env_lstnew(__environ[0]);
	if (__environ[0] == NULL)
	{
		return (env_lst_first);
	}
	i++;
	while (__environ[i] != NULL)
	{
		env_lstadd_back(&env_lst_first, env_lstnew(__environ[i]));
		i++;
	}
	env_lstadd_back(&env_lst_first, env_lstnew(NULL));
	return (env_lst_first);
}

// /// @brief
// /// @param lst
// /// @return
// void	**env_lst_to_str_array(t_env_lst *lst)
// {
// }

/// @brief Adds the node `new` at the end of the list.
/// @param lst The address of a pointer to the first node of a list.
/// @param new The address of a pointer to the node to be added.
void	env_lstadd_back(t_env_lst **lst, t_env_lst *new)
{
	t_env_lst	*last_element;

	last_element = env_lstlast(*lst);
	if (last_element == NULL)
	{
		*lst = new;
		return ;
	}
	last_element->next_env = new;
}

/// @brief Adds the node `new` at the beginning of the list.
/// @param lst The address of a pointer to the first node of a list.
/// @param new The address of a pointer to the node to be added.
/// @return None.
void	env_lstadd_front(t_env_lst **lst, t_env_lst *new)
{
	new->next_env = *lst;
	*lst = new;
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
void	envlst_clear(t_env_lst **stack)
{
	t_env_lst	*temp;

	while ((*stack) != NULL)
	{
		temp = (*stack)->next_env;
		envlst_del_one(*stack);
		*stack = temp;
	}
	free(*stack);
	*stack = NULL;
}

/// @brief Takes a node as parameter and frees its content
/// using the function `del`. Free the node itself but
/// does NOT free the next node.
/// @param lst The node to free.
/// @param del The address of the function used to delete the content.
void	envlst_del_one(t_env_lst *lst)
{
	free((lst)->env_value);
	free(lst);
}

/// @brief Print the contents of the stack using `ft_printf()`.
/// @param stack
void	envlst_print(t_env_lst **stack)
{
	t_env_lst	*temp;
	int		i;

	if (*stack == NULL)
	{
		ft_printf("Empty stack");
		return ;
	}
	// ft_printf("\n----- STACK CONTENTS -----\n");
	i = 0;
	temp = *stack;
	while (temp->next_env != NULL)
	{
		ft_printf("Node %i = %s | Node Address : %p | Next : %p\n", i, temp->env_value, temp, temp->next_env);
		temp = temp->next_env;
		i++;
	}
	ft_printf("Node %i = %s | Node Address : %p | Next : %p\n", i, temp->env_value, temp, temp->next_env);
}



// /// @brief Iterates through the list `lst` and applies the
// /// function `f` to the content of each node.
// /// @param lst The address of a pointer to a node.
// /// @param f The address of the function to apply to each
// /// node’s content.
// void	env_lstiter(t_env_lst *lst, void (*f)(void *))
// {
// 	t_env_lst	*temp;

// 	if (lst == NULL)
// 	{
// 		return ;
// 	}
// 	temp = lst;
// 	while (temp->next_env != NULL)
// 	{
// 		f(temp->env_key);
// 		f(temp->env_value);
// 		temp = temp->next_env;
// 	}
// 	f(temp->env_key);
// 	f(temp->env_value);
// }

/// @brief Returns the last node of the list.
/// @param lst The beginning of the list.
/// @return Last node of the list.
t_env_lst	*env_lstlast(t_env_lst *lst)
{
	t_env_lst	*ptr_lst;

	if (lst == NULL)
	{
		return (NULL);
	}
	ptr_lst = lst;
	while (ptr_lst->next_env != NULL)
	{
		ptr_lst = ptr_lst->next_env;
	}
	return (ptr_lst);
}

// static void	*env_lstmap_cleanup(t_env_lst **new_lst, void (*del)(void *))
// {
// 	env_lstclear(new_lst, del);
// 	free(*new_lst);
// 	*new_lst = NULL;
// 	return (NULL);
// }

// /// @brief This function works similarly as the `env_lstiter()` function,
// /// but it creates a completely new list.
// ///
// /// `env_lstmap()` iterates through the list `lst`, applies the
// /// function `f()` to each node’s content, and creates
// /// a new list resulting of the successive applications
// /// of the function `f()`.
// ///
// /// External functions : `malloc()`, `free()`.
// ///
// /// Principle :
// ///
// /// 1. Create a new list and initialize its content as `f()`
// /// of source's list content.
// ///
// /// 2. Go one element deeper in the source list.
// ///
// /// 3. Repeat until the end, add each new element to the back of the
// /// new list.
// ///
// /// 4. Check that the new list has the same number of elements
// /// as the source list :
// ///
// /// 5. If something is missing, a `malloc()` must have failed.
// /// In that case, `env_lstclear()` function will be used with the
// /// `del()` function as parameter to clear everything from the first element.
// /// The new list will also be freed with `free()`,
// /// and its pointer set to `NULL`.
// ///
// /// 6. Else, return the new list's pointer.
// ///
// /// @param lst The address of a pointer to a node.
// /// @param f The address of the function applied to each node’s content.
// /// @param del The address of the function used to delete a
// /// node’s content if needed.
// /// @return (Pointer to the new list); or `NULL` if any allocation fails.
// t_env_lst	*env_lstmap(t_env_lst *lst, void *(*f)(void *),
//		void (*del)(void *))
// {
// 	t_env_lst	*new_lst;
// 	t_env_lst	*temp_src;
// 	t_env_lst	*back_list;
// 	void		*content_temp;

// 	if (lst == NULL || f == NULL || del == NULL)
// 		return (NULL);
// 	temp_src = lst;
// 	content_temp = f(temp_src->content);
// 	if (content_temp == NULL)
// 		return (NULL);
// 	new_lst = env_lstnew(content_temp);
// 	if (new_lst == NULL)
// 		return (del(content_temp), NULL);
// 	while (temp_src->next_env != NULL)
// 	{
// 		content_temp = f((temp_src->next_env)->content);
// 		back_list = env_lstnew(content_temp);
// 		if (back_list == NULL)
// 			return (del(content_temp), env_lstmap_cleanup(&new_lst, del));
// 		env_lstadd_back(&new_lst, back_list);
// 		temp_src = temp_src->next_env;
// 	}
// 	return (new_lst);
// }

/// @brief Allocates memory (using `malloc()`) and returns
/// a new node.
///
/// - The `content` member variable is
/// initialized with the given parameter `content`.
///
/// - The variable `next` is initialized to `NULL`.
/// @param content The content to store in the new node.
/// @return A pointer to the new node.
/// @warning Subject does not specify the need to protect
/// if `malloc()` fails !
t_env_lst	*env_lstnew(char *value)
{
	t_env_lst	*new_node;

	new_node = malloc(sizeof(t_env_lst));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->env_value = ft_strdup(value);
	new_node->next_env = NULL;
	return (new_node);
}

/// @brief Counts the number of nodes in the list.
/// @param lst The beginning of the list.
/// @return The length of the list.
int	env_lstsize(t_env_lst *lst)
{
	int			i;
	t_env_lst	*ptr_lst;

	if (lst == NULL)
	{
		return (0);
	}
	ptr_lst = lst;
	i = 1;
	while (ptr_lst->next_env != NULL)
	{
		ptr_lst = ptr_lst->next_env;
		i++;
	}
	return (i);
}
