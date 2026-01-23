/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:54:25 by ancourti          #+#    #+#             */
/*   Updated: 2026/01/21 20:54:11 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Deletes and frees the given node and all its successors,
/// using the function `del` and `free()`.
/// Finally, set the pointer to the list to `NULL`.
///
/// Source code explaination :
///
/// 1. Loop over the list.
///
/// 2. Set `temp` to point to the next element of the list.
///
/// 3. Use `ft_lstdelone()` on the current element.
///
/// 4. Set the list pointer equal to `temp`, so that we have a
/// pointer to the next element.
///
/// 5. Finally, `free()` the list pointer and set it to `NULL`.
/// @param lst The address of a pointer to a node.
/// @param del The address of the function used to
/// delete the content of the node.
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while ((*lst) != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	free(*lst);
	*lst = NULL;
}
