/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 03:36:03 by ancourti          #+#    #+#             */
/*   Updated: 2026/01/21 20:54:56 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_lstmap_cleanup(t_list **new_lst, void (*del)(void *))
{
	ft_lstclear(new_lst, del);
	free(*new_lst);
	*new_lst = NULL;
	return (NULL);
}

/// @brief This function works similarly as the `ft_lstiter()` function,
/// but it creates a completely new list.
///
/// `ft_lstmap()` iterates through the list `lst`, applies the
/// function `f()` to each node’s content, and creates
/// a new list resulting of the successive applications
/// of the function `f()`.
///
/// External functions : `malloc()`, `free()`.
///
/// Principle :
///
/// 1. Create a new list and initialize its content as `f()`
/// of source's list content.
///
/// 2. Go one element deeper in the source list.
///
/// 3. Repeat until the end, add each new element to the back of the
/// new list.
///
/// 4. Check that the new list has the same number of elements
/// as the source list :
///
/// 5. If something is missing, a `malloc()` must have failed.
/// In that case, `ft_lstclear()` function will be used with the
/// `del()` function as parameter to clear everything from the first element.
/// The new list will also be freed with `free()`,
/// and its pointer set to `NULL`.
///
/// 6. Else, return the new list's pointer.
///
/// @param lst The address of a pointer to a node.
/// @param f The address of the function applied to each node’s content.
/// @param del The address of the function used to delete a
/// node’s content if needed.
/// @return (Pointer to the new list); or `NULL` if any allocation fails.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp_src;
	t_list	*back_list;
	void	*content_temp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	temp_src = lst;
	content_temp = f(temp_src->content);
	if (content_temp == NULL)
		return (NULL);
	new_lst = ft_lstnew(content_temp);
	if (new_lst == NULL)
		return (del(content_temp), NULL);
	while (temp_src->next != NULL)
	{
		content_temp = f((temp_src->next)->content);
		back_list = ft_lstnew(content_temp);
		if (back_list == NULL)
			return (del(content_temp), ft_lstmap_cleanup(&new_lst, del));
		ft_lstadd_back(&new_lst, back_list);
		temp_src = temp_src->next;
	}
	return (new_lst);
}
