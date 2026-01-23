/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 03:53:57 by ancourti          #+#    #+#             */
/*   Updated: 2026/01/21 20:52:13 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

// int	main(void)
// {
// 	t_list	*testlist = ft_lstnew("bonjour");
// 	printf("%s%s\n", "Content inside test_list : ", (char *)testlist->content);
// 	printf("%s%p\n", "Next item : ", &testlist->next);
// 	return (0);
// }
